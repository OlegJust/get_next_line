/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opidhorn <opidhorn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:28:35 by opidhorn          #+#    #+#             */
/*   Updated: 2024/12/08 20:01:33 by opidhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*crete_read_to_buffer(char **buffer, char **temp)
{
	char	*temp_buffer;
	char	*new_str;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	if (*buffer)
		while ((*buffer)[len1])
			len1++;
	len2 = 0;
	if (*temp)
		while ((*temp)[len2])
			len2++;
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = 0;
	if (*s1)
		while ((s1)[len])
			len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s1, len);
	dup[len] = '\0';
	return (dup);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	len_s;

	len_s = 0;
	if (*s)
		while ((s)[len_s])
			len_s++;
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s + start)
		len = len_s + start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
