/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:37:00 by fklein            #+#    #+#             */
/*   Updated: 2017/05/18 15:05:08 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	line(t_mlx *mlx, double x1, double y1, double x2, double y2)
{
	double	longueur;
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	i;
	
	if (ft_abs(x2 - x1) >= ft_abs(y2 - y1))
		longueur =  ft_abs(x2 - x1);
	else
		longueur = ft_abs(y2 - y1);
	dx = (x2 - x1) / longueur;
	dy = (y2 - y1) / longueur;
	x = x1 + 0.5;
	y = y1 + 0.5;
	i = 1;
	while (i <= longueur)
	{
		fill_pixel(mlx, (int)x, (int)y, 0xFFFFFF);
		x = x + dx;
		y = y + dy;
		i++;
	}
	return (0);
}

int	display(t_data *data, t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width - 1)
	{
		j = 0;
		while (j < data->height - 1)
		{
			line(mlx,
				(i + j) * 10 + 50,
				(j - i) * 5 + mlx->y_size / 2 - data->tab[j][i] * 10,
				(i + j + 1) * 10 + 50,
				(j + 1 - i) * 5 + mlx->y_size / 2 - data->tab[j + 1][i] * 10);
			line(mlx,
				(i + j) * 10 + 50,
				(j - i) * 5 + mlx->y_size / 2 - data->tab[j][i] * 10,
				(i + 1 + j) * 10 + 50,
				(j - i - 1) * 5 + mlx->y_size / 2 - data->tab[j][i + 1] * 10);
//			fill_pixel(mlx,
//				(i + j) * 10 + 50,
//				(j - i) * 5 + mlx->y_size / 2 - data->tab[j][i] * 10,
//				0xFFFFFF);
			j++;
		}
		i++;
	}
//	line(mlx, 0, 0, 300, 1);
	return (0);
}
