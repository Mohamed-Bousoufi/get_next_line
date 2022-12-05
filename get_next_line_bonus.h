/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:44:11 by mbousouf          #+#    #+#             */
/*   Updated: 2022/11/30 23:02:43 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

char	*t_strjoin(char *s1, char *s2);
char	*t_substr(char *s, unsigned int start, size_t len);
char	*t_strdup(const char *s1);
size_t	t_strlen(const char *s);
char	*red(char *save, int fd );
int		check(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*t_memmove(void *dest, const void *src, size_t n);

#endif