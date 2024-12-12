/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:28:44 by opidhorn          #+#    #+#             */
/*   Updated: 2024/12/11 17:21:57 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;


	// this line execute just for the first time
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
		// buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	temp = (char *)malloc(BUFFER_SIZE + 1);
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
		crete_read_to_buffer(&buffer, &temp);
		if (!buffer)
			return (safe_free(buffer));
	}
	free(temp);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_substr(buffer, 0, i + 0);
	return (line);
}

static char	*save_remainder(char *buffer)
{
	char	*remainder;
	size_t	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remainder = ft_strdup(buffer + i + 1);
	free(buffer);
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
