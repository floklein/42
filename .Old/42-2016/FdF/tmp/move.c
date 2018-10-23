/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:23:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 17:15:17 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	my_key_funct(int keycode, t_data *data)
{
	printf("key event %d\n", keycode);
	printf("mlx : %s | data : %s\n", data->mlx, data->win);
	if (keycode == 15)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00000000);
		data->x = 200;
		data->y = 200;
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FFFFFF);
	}
	if (keycode == 126)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00000000);
		data->y -= 5;
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FFFFFF);
	}
	if (keycode == 125)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00000000);
		data->y += 5;
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FFFFFF);
	}
	if (keycode == 123)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00000000);
		data->x -= 5;
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FFFFFF);
	}
	if (keycode == 124)
	{
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00000000);
		data->x += 5;
		mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FFFFFF);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main()
{
	void	*mlx;
	void	*win;
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "move");
	data->mlx = mlx;
	data->win = win;
	data->x = 200;
	data->y = 200;
	printf("mlx : %s | data : %s\n", data->mlx, data->win);
	mlx_key_hook(win, my_key_funct, data);
	mlx_loop(mlx);
	return (0);
}
