/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 07:37:38 by fklein            #+#    #+#             */
/*   Updated: 2017/05/17 12:45:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	expose_funct(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
	return (0);
}

int	key_funct(int keycode, t_mlx *mlx)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		expose_funct(mlx);
	return (0);
}

int	hex_to_int(int color, int *r, int *g, int *b)
{
	int	hex;

	hex = color;
	*r = hex / 65536;
	hex = hex - (*r * 65536);
	*g = hex / 256;
	hex = hex - (*g * 256);
	*b = hex;
	return (0);
}

int	fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	r;
	int	g;
	int	b;

	hex_to_int(color, &r, &g, &b);
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y)] = b; //b
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 1] = g; //g
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 2] = r; //r
	mlx->img_str[(x * 4) + (4 * mlx->x_size * y) + 3] = '1';
	printf("r: %d, g: %d, b: %d\n", r, g, b);
	return (0);
}

int	fdf(t_data *data)
{
	t_mlx	*mlx;
	int	bpp;
	int	s_l;
	int	endian;
	int	i;
	int	j;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	mlx->ptr = mlx_init();
	printf("width: %d, height: %d\n", data->width, data->height);
	mlx->x_size = data->width * 30;
	mlx->y_size = data->height * 40;
	mlx->win = mlx_new_window(mlx, mlx->x_size, mlx->y_size, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->x_size, mlx->y_size);
	mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp, &s_l, &endian);
	i = 0;
	printf("bpp: %d, s_l: %d, endian: %d\n", bpp, s_l, endian);
	while (i < data->width)
	{
		j = 0;
		while (j < data->height)
		{
			if (data->tab[j][i] != 0)
				fill_pixel(mlx, i * 30, j * 30, 0xFFFFFF);
			j++;
		}
		i++;
	}
//	printf("%s\n", mlx->img_str);
	mlx_expose_hook(mlx->win, expose_funct, mlx);
	mlx_key_hook(mlx->win, key_funct, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
