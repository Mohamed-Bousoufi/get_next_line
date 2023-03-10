/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:02:49 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/10 23:27:19 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*t_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ptr;
	int		j;

	if (!s1)
		s1 = t_strdup("");
	if (!s2)
		return ((char *)s1);
	j = 0;
	s1len = t_strlen(s1);
	s2len = t_strlen(s2);
		ptr = (char *)malloc(s2len + s1len + 1);
	if (!ptr)
		return (NULL);
	t_memmove(ptr, s1, s1len);
	while (s2len)
	{
			ptr[s1len++] = s2[j++];
				s2len--;
	}
		ptr[s1len] = '\0';
	free(s1);
	return (ptr);
}

char	*t_substr(char *s, int unsigned start, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	if (s == NULL && len >= 0)
		return (0);
	if (start >= (unsigned int)t_strlen(s))
	{
		return (0);
	}
	if (len > t_strlen(s) - start)
		len = t_strlen(s) - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (len)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}

char	*t_strdup(char *s1)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(t_strlen(s1) + 1);
	if (!p)
	{
		return (0);
		free(p);
	}
	while (i < t_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	len = (t_strlen(s) + 1);
	while (len > 0)
	{
		if (*s == (char)c)
		{
			ptr = (char *)s;
			break ;
		}
		else
			ptr = NULL;
		s++;
		len--;
	}
	return (ptr);
}

void	*t_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	char				*ds;
	const char			*sc;

	if (!dest && !src)
		return (0);
	i = n;
	ds = dest;
	sc = src;
	while (n--)
	{
		if (ds < sc)
			*ds++ = *sc++;
		else
			*(ds + n) = *(sc + n);
	}
	return (dest);
}
