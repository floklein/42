/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:49 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 22:10:52 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x <= mlx->width && y <= mlx->height)
		mlx->data[x + mlx->width * y] = color;
}

void	ft_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2)
{
	int		dx;
	int		dy;
	int		e;

	e = coord2->x - coord1->x;
	dx = e * 2;
	dy = (coord2->y - coord1->y) * 2;
	while (coord1->x <= coord2->x)
	{
		ft_fill_pixel(mlx, coord1->x, coord1->y, coord1->color);
		coord1->x++;
		if ((e -= dy) <= 0)
		{
			coord1->y++;
			e += dx;
		}
	}
}
