/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:03 by flklein           #+#    #+#             */
/*   Updated: 2018/11/13 18:27:18 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*ft_newfile(int fd)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->buf = NULL;
	return (file);
}

char	**ft_getfile(t_file **file, int fd)
{
	if (*file)
	{
		if ((*file)->fd == fd)
			return (&((*file)->buf));
		else if ((*file)->next)
			return (ft_getfile(&((*file)->next), fd));
		else
		{
			(*file)->next = ft_newfile(fd);
			return (&((*file)->next->buf));
		}
	}
	else
	{
		*file = ft_newfile(fd);
		return (&((*file)->buf));
	}
}

char	ft_treatbuffer(char **line, char **buf)
{
	int		i;

	i = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i] == '\n')
	{
		*line = ft_strjoin(*line, ft_strsub(*buf, 0, i));
		*buf += i + 1;
		return ('\n');
	}
	else
	{
		*line = ft_strjoin(*line, *buf);
		return (0);
	}
}

int		get_next_line(const int fd, char **line)
{
	int				r;
	static t_file	*file = NULL;
	char			**buf;

	if (fd < 0 || !line || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!file)
		if (!(file = ft_newfile(fd)))
			return (-1);
	buf = ft_getfile(&file, fd);
	if (*buf)
		if (ft_treatbuffer(line, buf) == '\n')
			return (1);
	if (!(*buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((r = read(fd, *buf, BUFF_SIZE)))
	{
		(*buf)[r] = '\0';
		if (ft_treatbuffer(line, buf) == '\n')
			return (1);
	}
	if (r == 0)
		return (0);
	else
		return (1);
}
