/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:37:00 by fklein            #+#    #+#             */
/*   Updated: 2017/05/19 14:58:24 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y)] = color / 65536;
	color -= (mlx->img_str[(x * 4) + (4 * mlx->x_size * y)]) * 65536;
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 1] = color / 256;
	color -= (mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 1]) * 256;
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 2] = color;
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 3] = '1';
	return (0);
}

int	line(t_mlx *mlx, double x1, double y1, double x2, double y2)
{
	int	lenght;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int	i;

	if (ft_abs(x2 - x1) >= ft_abs(y2 - y1))
		lenght =  ft_abs(x2 - x1);
	else
		lenght = ft_abs(y2 - y1);
	dx = (x2 - x1) / lenght;
	dy = (y2 - y1) / lenght;
	x = x1 + 0.5;
	y = y1 + 0.5;
	i = 1;
	while (i <= lenght)
	{
		fill_pixel(mlx, (int)x, (int)y, 0xFFFFFF);
		x += dx;
		y += dy;
		i++;
	}
	return (0);
}

int	display(t_data *data, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->width)
	{
		j = 0;
		while (j < data->height - 1)
		{
			line(mlx,
					(i + j) * 16 + data->width,
					(j - i) * 8 - data->tab[j][i] * 16 + data->max * 30,
					(i + j + 1) * 16 + data->width,
					(j + 1 - i) * 8 - data->tab[j + 1][i] * 16 + data->max * 30);
			line(mlx,
					(i + j) * 16 + data->width,
					(j - i) * 8 - data->tab[j][i] * 16 + data->max * 30,
					(i - 1 + j) * 16 + data->width,
					(j - i + 1) * 8 - data->tab[j][i - 1] * 16 + data->max * 30);
//			fill_pixel(mlx,
//				(i + j) * 10 + 50,
//				(j - i) * 5 + mlx->y_size / 2 - data->tab[j][i] * 10,
//				0xFFFFFF);
			j++;
		}
		i++;
	}
	return (0);
}
