/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:28:23 by fklein            #+#    #+#             */
/*   Updated: 2017/07/23 20:22:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>

int	first_time(int fd, t_stockage *stock)
{
	int			err;
	char		*ch;
	char		*tmp_str;

	if (!(ch = (char *)malloc(sizeof(char) * BUFF_SIZE))
	|| !(tmp_str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while ((err = read(fd, ch, BUFF_SIZE)) > 0)
	{
		tmp_str = ft_strjoin(tmp_str, ch);
		ft_strclr(ch);
	}
	if (err == -1 && errno == EBADF)
		return (0);
	stock->files[fd] = ft_strsplit_mod(tmp_str, '\n');
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static t_stockage	*stock = NULL;

	if (fd < 0)
		return (-1);
	if (!stock)
		if (!(stock = (t_stockage *)malloc(sizeof(t_stockage)))
		|| !(stock->tries = (int *)malloc(sizeof(int) * 100))
		|| !(stock->files = (char ***)malloc(sizeof(char **) * 100)))
			return (-1);
	if (stock->tries[fd] == 0)
		if (!first_time(fd, stock))
			return (-1);
	*line = stock->files[fd][stock->tries[fd]];
	if (stock->files[fd][stock->tries[fd] + 1] == NULL)
		return (0);
	stock->tries[fd]++;
	return (1);
}
