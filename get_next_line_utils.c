/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:11:06 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/13 18:58:05 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	size;
	size_t	offset;

	size = ft_strlen(str);
	ret = malloc(size + 1);
	offset = 0;
	while (str[offset])
	{
		ret[offset] = str[offset];
		offset++;
	}
	ret[offset] = '\0';
	return (ret);
}

char	*ft_strndup(char *reminder, size_t end)
{
	char	*dup;
	size_t	offset;

	dup = malloc(end + 1);
	if (dup == NULL)
		return (NULL);
	offset = 0;
	while (offset < end)
	{
		dup[offset] = reminder[offset];
		offset++;
	}
	dup[offset] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*res;
	size_t	offset;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (*s1)
		res[offset++] = *s1++;
	while (*s2)
		res[offset++] = *s2++;
	res[offset] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	to_find;

	if (s == NULL)
		return (NULL);
	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	if (*str == to_find)
		return ((char *)str);
	while (*str++)
	{
		if (*str == to_find)
			return ((char *)str);
	}
	return (NULL);
}
