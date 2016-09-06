/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetri2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:53:36 by dsmite            #+#    #+#             */
/*   Updated: 2016/04/30 17:54:30 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	stock_pos(int x, int y, int *pos_ref, int *pos_tab)
{
	pos_tab[0] = y - pos_ref[0];
	pos_tab[1] = x - pos_ref[1];
}

void	get_pos_ref(int x, int y, int *pos_ref, int count)
{
	if (count == 0)
	{
		pos_ref[0] = y;
		pos_ref[1] = x;
	}
}

void	get_block_pos(char *buf, t_tetri *tetri, int nb, int *pos_ref)
{
	int		x;
	int		y;
	int		i;
	int		count;

	y = 0;
	x = 0;
	i = 0;
	count = 0;
	while (y < 4)
	{
		if (buf[i] == '#')
		{
			get_pos_ref(x, y, pos_ref, count);
			stock_pos(x, y, pos_ref, tetri[nb].pos[count]);
			count++;
		}
		x++;
		if (buf[i] == '\n')
		{
			x = 0;
			y++;
		}
		i++;
	}
}
