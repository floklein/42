/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:08:14 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 13:15:51 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		is_overlapping(t_tetri *tetri, int i)
{
	int			j;
	int			k;
	int			l;
	t_tetri		tmp;
	t_tetri		tetrii;

	j = -1;
	tetrii = tetri[i];
	while (++j < i)
	{
		tmp = tetri[j];
		k = -1;
		while (++k < 4)
		{
			l = -1;
			while (++l < 4)
			{
				if ((tetrii.sq_x + tetrii.pos[l][1] == tmp.sq_x + tmp.pos[k][1])
						&& (tetrii.sq_y + tetrii.pos[l][0] == tmp.sq_y +
							tmp.pos[k][0]))
					return (1);
			}
		}
	}
	return (0);
}

int		is_outside(t_tetri tetri, t_square *sq)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = tetri.pos[i][1] + tetri.sq_x;
		y = tetri.pos[i][0] + tetri.sq_y;
		if ((x > sq->x_max - 1) || (y > sq->y_max - 1) ||
				x < 0 || y < 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_sqrt(int nb)
{
	int		n;

	n = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (n * n != nb)
	{
		if (n * n > nb)
			return (0);
		n++;
	}
	return (n);
}
