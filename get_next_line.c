/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:28:23 by snovaes           #+#    #+#             */
/*   Updated: 2021/06/10 22:31:43 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	kill(char **reminder)
{
	if (*reminder != NULL)
	{
		free(*reminder);
		*reminder = NULL;
	}
}

static int	linelen(char *line)
{
	size_t	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

static int	get_line(char **reminder, char **line)
{
	size_t	size;
	char	*temp;

	size = linelen(*reminder);
	if ((*reminder)[size] == '\0')
	{
		*line = ft_strdup(*reminder);
		kill(reminder);
		return (0);
	}
	*line = linedup(*reminder, size);
	temp = ft_strdup((*reminder) + size + 1);
	free(*reminder);
	*reminder = temp;
	return (1);
}

static int	output(char **reminder, char **line, ssize_t size_read)
{
	if (size_read == -1)
		return (-1);
	else if (size_read == 0 && *reminder == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (get_line(reminder, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*reminder;
	ssize_t		size_read;
	char		*buffer;
	char		*new_line;

	buffer = malloc(BUFFER_SIZE + 1);
	size_read = read(fd, buffer, BUFFER_SIZE);
	while (size_read > 0)
	{
		buffer[size_read] = '\0';
		if (reminder == NULL)
			reminder = ft_strdup(buffer);
		else
		{
			new_line = ft_strjoin(reminder, buffer);
			free(reminder);
			reminder = new_line;
		}
		if (ft_strchr(reminder, '\n'))
			break ;
		size_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(&reminder, line, size_read));
}
