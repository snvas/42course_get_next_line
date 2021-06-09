/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:44:41 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/08 22:24:53 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}


static	char	*check_reminder(char *reminder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (reminder)
	{
		p_n = ft_strchr(reminder, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			while (*reminder)	
				*reminder++ = '\0';
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

static int	get_line(int fd, char **line, char **reminder)
{
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;
	char		*p_n;
	char		*tmp;

	p_n = check_reminder(*reminder, line);
	while (!p_n && (byte_was_read))
	{
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			*reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!(*line) || byte_was_read < 0)
			return (-1);
		free(tmp);
	}
	return (byte_was_read != 0 || ft_strlen(*line) != 0);
}

GNL	*new_linked_list_el(int fd)
{
	GNL	*new;

	new = (GNL *)malloc(sizeof(GNL));
	new->fd = fd;
	new->reminder = NULL;
	new->next = NULL;
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static GNL	*head;
	GNL			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (head == NULL)
		head = new_linked_list_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list_el(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->reminder));
}

