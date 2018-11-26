/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:49 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 00:33:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->data[x + mlx->width * y] = color;
}

void	ft_line(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		p;
	int		x;
	int		y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			ft_fill_pixel(mlx, x, y, 0xFFFFFF);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			ft_fill_pixel(mlx, x, y, 0xFFFFFF);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}
