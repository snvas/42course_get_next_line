/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:43:53 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/08 14:19:34 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_get_next_line
{
	int						fd;
	char					*reminder;
	struct s_get_next_line	*next;
}	GNL;

static	char	*check_reminder(char *reminder, char **line);
static int	get_line(int fd, char **line, char **reminder);
GNL	*new_linked_list_el(int fd);
int	get_next_line(int fd, char **line);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
#endif