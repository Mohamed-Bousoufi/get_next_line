/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:05:38 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/10 23:23:50 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	t_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	else
		while (s[i])
			i++;
	return (i);
}

int	check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*red(char *save, int fd )
{
	int		r;
	char	*s;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (free(s), free(save), NULL);
	r = read(fd, s, BUFFER_SIZE);
	if (r < 0)
		return (free(s), free(save), NULL);
	while (r > 0)
	{
		s[r] = '\0';
		if (save || ft_strchr(s, '\n'))
		{
			if (ft_strchr(save, '\n') || ft_strchr(s, '\n'))
			{
				save = t_strjoin(save, s);
				break ;
			}
		}
		save = t_strjoin(save, s);
		r = read(fd, s, BUFFER_SIZE);
	}
	return (free (s), save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	char		*c;
	int			i;
	size_t		j;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = red(save, fd);
	i = check(save);
	j = (t_strlen(save));
	line = t_substr(save, 0, i + 1);
	c = t_substr(save, (i + 1), j);
	free(save);
	save = c;
	if (t_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
