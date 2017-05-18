/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:37:00 by fklein            #+#    #+#             */
/*   Updated: 2017/05/18 14:30:10 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	line(t_mlx *mlx, double x1, double y1, double x2, double y2)
{
	double	i;
	double	j;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	jj;

	xmin = (x1 < x2 ? x1 : x2);
	xmax = (y1 > x2 ? x1 : x2) + 1;
	ymin = (y1 < y2 ? y1 : y2);
	ymax = (y1 > y2 ? y1 : y2) + 1;
	printf("xmin: %f, ymin: %f, xmax: %f, ymax: %f\n", xmin, ymin, xmax, ymax);
	j = ymin;
	while (j <= ymax)
	{
		i = xmin;
		while (i <= xmax)
		{
			jj = i * (ymax - ymin) / (xmax - xmin)
				+ ymax - xmax * (ymax - ymin) / (xmax - xmin);
//			printf("i: %f, j?= %f\n", i, jj);
			if ((int)j == (int)jj)
			{
				fill_pixel(mlx, (int)i, (int)j, 0xFFFFFF);
//				printf("-- printed: %d / %d\n", (int)i, (int)j);
			}
			i += 0.01;
		}
		j += 0.01;
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
				(j + 1 - i) * 5 + mlx->y_size / 2 - data->tab[j][i + 1] * 10);
			line(mlx,
				(i + j) * 10 + 50,
				(j - i) * 5 + mlx->y_size / 2 - data->tab[j][i] * 10,
				(i + 1 + j) * 10 + 50,
				(j - i - 1) * 5 + mlx->y_size / 2 - data->tab[j + 1][i] * 10);
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
