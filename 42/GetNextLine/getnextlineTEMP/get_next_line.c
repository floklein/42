/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:28:23 by fklein            #+#    #+#             */
/*   Updated: 2017/03/05 23:29:49 by fklein           ###   ########.fr       */
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

int	get_next_line(int fd, char **line)
{
	static stockage	*stock = NULL;
	int		err;
	char		*ch;
	char		*tmp_str;

	if (fd < 0)
		return (-1);
	if (!stock)
	{
		if (!(stock = (stockage *)malloc(sizeof(stockage)))
		|| !(stock->tries = (int *)malloc(sizeof(int) * 1000))
		|| !(stock->files = (char ***)malloc(sizeof(char **) * 1000)))
			return (-1);
	}
	if (stock->tries[fd] == 0)
	{
		if (!(ch = (char *)malloc(sizeof(char) * BUFF_SIZE))
		|| !(tmp_str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		while ((err = read(fd, ch, BUFF_SIZE)) > 0)
		{	
			tmp_str = ft_strjoin(tmp_str, ch);
			ft_strclr(ch);
		}
		if (err == -1 && errno == EBADF)
			return (-1);
		stock->files[fd] = ft_strsplit_mod(tmp_str, '\n');
	}
	*line = stock->files[fd][stock->tries[fd]];
	if (stock->files[fd][stock->tries[fd] + 1] == NULL)
		return (0);
	stock->tries[fd]++;
	return (1);
}
