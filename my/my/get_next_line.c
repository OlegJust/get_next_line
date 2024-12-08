/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:28:44 by opidhorn          #+#    #+#             */
/*   Updated: 2024/12/07 14:50:55 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	*safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*create_read_to_buffer(char **buffer, char **temp)
{
	char	*temp_buffer;
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(*buffer);
	len2 = ft_strlen(*temp);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, *buffer, len1);
	ft_memmove(new_str + len1, *temp, len2);
	new_str[len1 + len2] = '\0';
	temp_buffer = new_str;
	free(*buffer);
	*buffer = temp_buffer;
	if (!buffer)
		free(temp);
	return (0);
}

static char *read_to_buffer(int fd, char *buffer)
{
    char *temp;
    int bytes_read;

    if (!buffer)
        buffer = ft_strdup(""); // Start with an empty string
    if (!buffer)
        return (NULL);
    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return (safe_free(buffer));
    while (!ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read < 0)
            return (safe_free(temp), safe_free(buffer));
        if (bytes_read == 0)
            break ;
        temp[bytes_read] = '\0';
        create_read_to_buffer(&buffer, &temp);
        if (!buffer)
            return (safe_free(temp));
    }
    free(temp);
    return (buffer);
}

static char *extract_line(char *buffer)
{
    size_t i;
    char *line;

    if (!buffer || !*buffer)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n') // Include newline in the line
        line = ft_substr(buffer, 0, i + 1);
    else
        line = ft_substr(buffer, 0, i); // No newline
    return (line);
}


static char *save_remainder(char *buffer)
{
    size_t i;
    char *remainder;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i]) // No newline found
        return (safe_free(buffer));
    remainder = ft_strdup(buffer + i + 1); // Duplicate after the newline
    free(buffer);
    if (!remainder)
        return (NULL);
    return (remainder);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = save_remainder(buffer);
	return (line);
}
