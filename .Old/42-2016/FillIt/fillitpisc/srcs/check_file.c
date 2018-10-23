/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:47:25 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/02 00:58:27 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		check_connections(char *buf, int i)
{
	int		connect_nb;

	connect_nb = 0;
	if (i + 1 < 20)
	{
		if (buf[i + 1] == '#')
			connect_nb++;
	}
	if (i - 1 >= 0)
	{
		if (buf[i - 1] == '#')
			connect_nb++;
	}
	if (i + 5 < 20)
	{
		if (buf[i + 5] == '#')
			connect_nb++;
	}
	if (i - 5 >= 0)
	{
		if (buf[i - 5] == '#')
			connect_nb++;
	}
	return (connect_nb);
}

int		block_neighbors(char *buf)
{
	int	i;
	int	connect_nb;
	int	one_neighbors;

	i = 0;
	connect_nb = 0;
	one_neighbors = 0;
	while (i != 20)
	{
		if (buf[i] == '#')
		{
			connect_nb = check_connections(buf, i);
			if (connect_nb == 0)
				return (1);
			if (connect_nb == 1)
				one_neighbors++;
		}
		i++;
	}
	if (one_neighbors > 3)
		return (1);
	return (0);
}

int		check_buf(char *buf)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (buf[i] && i != 20)
	{
		if (buf[i] == '\n' && i != 4 && i != 9 && i != 14 && i != 19)
			return (1);
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (1);
		if (buf[i] == '#')
			block++;
		i++;
	}
	if (buf[20] != '\n' && buf[20] != '\0')
		return (1);
	if ((i < 20 || i > 21) || block != 4)
		return (1);
	if (buf[20] == '\n')
		return (2);
	return (0);
}

int		read_file(char *buf, int fd, int *tetri_nb)
{
	int		last_char;

	*tetri_nb = 0;
	last_char = -1;
	while (read(fd, buf, 21))
	{
		if ((last_char = check_buf(buf)) == 1 || block_neighbors(buf) == 1)
		{
			close(fd);
			return (1);
		}
		*tetri_nb += 1;
		ft_bzero(buf, 22);
	}
	if (*tetri_nb > 26)
		return (1);
	return (last_char);
}

int		check_file(char *file, int *tetri_nb)
{
	int		fd;
	char	buf[22];

	ft_bzero(buf, 22);
	if ((fd = open(file, O_RDONLY)) != -1 && open(file, O_DIRECTORY) == -1)
	{
		if (read_file(buf, fd, tetri_nb))
		{
			close(fd);
			return (1);
		}
		if (close(fd))
			return (1);
	}
	else
		return (1);
	return (0);
}
