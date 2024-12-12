/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:43:40 by asemykin          #+#    #+#             */
/*   Updated: 2024/12/11 16:39:53 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_combine(const char *str_chunk, int byte, char *str_long,
		size_t *len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	if (str_long != NULL)
	{
		dest = ft_strdup(str_long, byte + *len);
		i = *len;
	}
	j = 0;
	while (str_chunk[j] != '\0')
	{
		dest[i + j] = str_chunk[j];
		j++;
	}
	dest[i + j] = '\0';
	*len = i + j;
	free(str_long);
	return (dest);
}

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s, size_t byte_len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)malloc(byte_len + 1);
	if (d == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
