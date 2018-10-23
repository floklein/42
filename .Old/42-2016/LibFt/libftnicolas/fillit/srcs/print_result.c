/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 00:23:22 by dsmite            #+#    #+#             */
/*   Updated: 2016/04/30 17:37:40 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		print_tetri(t_tetri tetri, int *x, int y, int *count)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tetri.sq_x + tetri.pos[i][1] == *x &&
				tetri.sq_y + tetri.pos[i][0] == y)
		{
			ft_putchar(tetri.c);
			(*count)++;
			return ;
		}
		i++;
	}
}

void		print_result(t_tetri *tetri, int tetri_nb, t_square sq)
{
	int		i;
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y < sq.y_max)
	{
		x = -1;
		while (++x < sq.x_max)
		{
			i = -1;
			count = 0;
			while (++i < tetri_nb)
				print_tetri(tetri[i], &x, y, &count);
			if (!count)
				ft_putchar('.');
		}
		ft_putchar('\n');
	}
}
