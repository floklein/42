/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:53:01 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 16:10:12 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		define_pos_tab(t_tetri *tetri, int tetri_nb)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < tetri_nb)
	{
		if ((tetri[i].pos = (int**)malloc(sizeof(int *) * 4)) == NULL)
			return (1);
		while (y < 4)
		{
			if ((tetri[i].pos[y] = (int*)malloc(sizeof(int) * 2)) == NULL)
				return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

void	get_infos(int fd, t_tetri *tetri)
{
	int		nb;
	char	buf[22];
	int		pos_ref[2];
	char	c;

	nb = 0;
	c = 'A';
	ft_bzero(buf, 22);
	while (read(fd, buf, 21))
	{
		get_block_pos(buf, tetri, nb, pos_ref);
		tetri[nb].c = c + nb;
		ft_bzero(buf, 22);
		nb++;
	}
}

t_tetri	*stock_tetri(char *file, int tetri_nb)
{
	int		fd;
	t_tetri	*tetri;

	if ((tetri = (t_tetri*)malloc(sizeof(t_tetri) * tetri_nb)) == NULL)
		return (NULL);
	if (define_pos_tab(tetri, tetri_nb))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	get_infos(fd, tetri);
	if (close(fd))
		return (NULL);
	return (tetri);
}
