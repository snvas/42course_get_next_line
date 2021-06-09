/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:02:11 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/06 20:51:49 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define OPEN_MAX 1024

typedef enum e_status
{
	ERROR = -1,
	END_OF_FILE,
	NEWLINE,
}	t_status;

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *str);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

char	*linedup(char *save, size_t end);

#endif