/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:03 by flklein           #+#    #+#             */
/*   Updated: 2018/12/06 18:51:16 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file			*ft_newfile(int fd)
{
	t_file		*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->fd = fd;
	file->data = NULL;
	file->next = NULL;
	return (file);
}

t_file			*ft_srchfile(t_file *file, int fd)
{
	if (file)
	{
		if (file->fd == fd)
			return (file);
		else if (file->next)
			return (ft_srchfile(file->next, fd));
		file->next = ft_newfile(fd);
		return (file->next);
	}
	file = ft_newfile(fd);
	return (file);
}

int				ft_delelem(t_file **file, int fd, int ret)
{
	t_file		*last;
	t_file		*tofree;

	last = *file;
	while (last->fd != fd && last->next && last->next->fd != fd)
		last = last->next;
	tofree = last->fd == fd ? last : last->next;
	if (last->fd == fd)
		*file = tofree->next;
	else
		last->next = tofree->next;
	ft_strdel(&(tofree->data));
	free(tofree);
	return (ret);
}

int				ft_treat(char **data, char **line)
{
	char	*tmp;
	int		len_l;

	len_l = 0;
	while ((*data)[len_l] && (*data)[len_l] != '\n')
		len_l++;
	if (((*data)[len_l]) == '\n')
	{
		*line = ft_strsub(*data, 0, len_l);
		tmp = *data;
		*data = ft_strdup(&(*data)[len_l + 1]);
		free(tmp);
		!(*data)[0] ? ft_strdel(data) : 0;
	}
	else if (!((*data)[len_l]))
	{
		*line = ft_strdup(*data);
		ft_strdel(data);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*cur;
	char			*tmp;
	char			*buf;
	int				r;

	if (fd < 0 || !line || (!file && !(file = ft_newfile(fd))))
		return (-1);
	cur = ft_srchfile(file, fd);
	if (!cur || (!(cur->data) && !(cur->data = ft_strnew(0))) ||
			!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(r = 0) && !ft_strchr(cur->data, '\n') && !ft_strchr(buf, '\n')
			&& (r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = 0;
		tmp = cur->data;
		cur->data = ft_strjoin(cur->data, buf);
		free(tmp);
	}
	free(buf);
	if (r < 0 || (r == 0 && (!(cur->data) || !(cur->data)[0])))
		return (ft_delelem(&file, fd, r < 0 ? -1 : 0));
	return (ft_treat(&(cur->data), line));
}
