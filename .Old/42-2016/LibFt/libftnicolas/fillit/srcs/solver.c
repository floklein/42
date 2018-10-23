/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:08:14 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 15:24:34 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	set_position(t_tetri *tetri, int i, int x, int y)
{
	tetri[i].sq_x = x;
	tetri[i].sq_y = y;
}

void	clear_positions(t_tetri *tetri, int tetri_nb)
{
	int		i;

	i = 0;
	while (i < tetri_nb)
	{
		set_position(tetri, i, -1, -1);
		i++;
	}
}

int		insert_tetri(t_tetri *tetri, int i, t_square *sq, int tetri_nb)
{
	int		x;
	int		y;

	y = 0;
	while (y < sq->y_max)
	{
		x = 0;
		while (x < sq->x_max)
		{
			set_position(tetri, i, x, y);
			if (!is_outside(tetri[i], sq) && !is_overlapping(tetri, i))
			{
				if (i == tetri_nb - 1)
					return (1);
				if (insert_tetri(tetri, i + 1, sq, tetri_nb))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	init_square(t_square **sq, int tetri_nb)
{
	int		n;
	int		n_block;

	n = 0;
	n_block = tetri_nb * 4;
	while (!n)
	{
		n = ft_sqrt(n_block);
		n_block++;
	}
	(*sq)->x_max = n;
	(*sq)->y_max = n;
}

void	solver(t_tetri *tetri, t_square **sq, int tetri_nb)
{
	init_square(sq, tetri_nb);
	clear_positions(tetri, tetri_nb);
	while (!insert_tetri(tetri, 0, *sq, tetri_nb))
	{
		clear_positions(tetri, tetri_nb);
		(*sq)->x_max++;
		(*sq)->y_max++;
	}
}
