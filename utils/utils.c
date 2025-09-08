/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:32:47 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/06 20:57:07 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*s2_start;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = (char *)ft_malloc(s1_len + 1);
	if (!s2)
		return (NULL);
	s2_start = s2;
	while (*s1)
		*(s2++) = *(s1++);
	*s2 = '\0';
	return (s2_start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3_start;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)ft_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	s3_start = s3;
	while (*s1)
		*(s3++) = *(s1++);
	while (*s2)
		*(s3++) = *(s2++);
	*s3 = '\0';
	return (s3_start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	srclen;
	size_t	i;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start >= srclen)
		return (ft_strdup(""));
	if (len > srclen - start)
		len = srclen - start;
	dst = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
