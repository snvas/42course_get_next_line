/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:44:41 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/04 21:59:44 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

static char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

static char *check_reminder(char *reminder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (reminder)
	{
		if((p_n = ft_strchr(reminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			ft_strclr(reminder);
		}
	}
	else
		*line = ft_strnew(1);
	return(p_n);
}

int	get_next_line(int fd, char **line)
{
	static char	*reminder;
	char		buf[BUFF_SIZE + 1];
	int			byte_was_read;
	char		*p_n;
	char		*tmp;

	p_n = check_reminder(reminder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if(p_n = ft_strchr(buf, '\n'))
		{
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (byte_was_read != 0 || ft_strlen(*line) != 0)
		return(1);
	else
		return (0);
}

int main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n\n", line);


	
}
