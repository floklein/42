/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 07:37:38 by fklein            #+#    #+#             */
/*   Updated: 2017/07/28 11:40:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	expose_funct(t_mlx *mlx)
{
	int	bpp;
	int	s_l;
	int	endian;

	mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->x_size, mlx->y_size);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp, &s_l, &endian);
	display(&mlx->data, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	return (0);
}

int	key_funct(int keycode, t_mlx *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		free(mlx);
		exit(0);
	}
	if (keycode == 49)
		expose_funct(mlx);
	return (0);
}

int	window_size(t_mlx *mlx, t_data *data)
{
	mlx->x_size = (data->width > data->height ? data->width : data->height) * 30;
	mlx->y_size = (data->height > data->width ? data->height : data->width) * 15
		+ data->max * 30
		+ ft_abs(data->min) * 30;
	if (mlx->x_size > 1920 || mlx->y_size > 1080)
	{
		mlx->y_unit = 8 / (mlx->y_size / 1080);
		mlx->x_unit = mlx->y_unit * 2;
		mlx->z_unit = mlx->x_unit;
		mlx->x_size = 1920;
		mlx->y_size = 1080;
	}
	else
	{
		mlx->x_unit = 16;
		mlx->y_unit = 8;
		mlx->z_unit = 16;
	}
	printf("x_unit: %d, y_unit: %d, z_unit: %d\n", mlx->x_unit, mlx->y_unit, mlx->z_unit);
	return (0);
}

int	fdf(t_data *data)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	mlx->ptr = mlx_init();
	window_size(mlx, data);
	printf("x_size: %d, y_size: %d\n", mlx->x_size, mlx->y_size);
	mlx->win = mlx_new_window(mlx, mlx->x_size, mlx->y_size, "fdf");
	mlx->data = *data;
	expose_funct(mlx);
	mlx_expose_hook(mlx->win, expose_funct, mlx);
	mlx_key_hook(mlx->win, key_funct, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
