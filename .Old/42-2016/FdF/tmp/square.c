/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:23:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/31 12:34:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	square(t_data *data, int x, int y, int x2, int y2, int color)
{
	int	i = x - 1;
	int	j = y - 1;

	while (i++ <= x2 + 1)
	{
		while (j++ <= y2 + 1)
			mlx_pixel_put(data->mlx, data->win, i, j, color);
		j = y - 1;
	}
	return (0);
}

int	reset(t_data *data)
{	
		square(data, 0, 0, data->x_size, data->y_size, 0x00000000);
		data->x = 350;
		data->y = 350;
		data->x2 = 450;
		data->y2 = 450;
		square(data, data->x, data->y, data->x2, data->y2, 0x00FFFFFF);
		return (0);
}

int	move(t_data *data, int keycode)
{
	square(data, data->x, data->y, data->x2, data->y2, 0x00000000);
	if (keycode == 126 || keycode == 125)
	{
		data->y += (keycode - 125 ? -5 : 5);
		data->y2 += (keycode - 125 ? -5 : 5);
	}
	if (keycode == 123 || keycode == 124)
	{
		data->x += (keycode - 123 ? 5 : -5);
		data->x2 += (keycode - 123 ? 5 : -5);
	}
	square(data, data->x, data->y, data->x2, data->y2, 0x00FFFFFF);
	return (0);
}

int	my_key_funct(int keycode, t_data *data)
{
	printf("key event %d\n", keycode);
	if (keycode == 15)
		reset(data);
	move(data, keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	my_mouse_funct(int button, int x, int y, t_data *data)
{
	if (x >= data->x && x <= data->x2 && y >= data->y && y <= data->y2)
	{
		printf("touched - button : %d | x : %d | y : %d\n", button, x, y);
		square(data, (x - 5 > data->x ? x - 5 : data->x),
					(y - 5 > data->y ? y - 5 : data->y),
					(x + 5 < data->x2 ? x + 5 : data->x2),
					(y + 5 < data->y2 ? y + 5 : data->y2),
					0x00FF0000);
	}
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
	data->x_size = 800;
	data->y_size = 800;
	win = mlx_new_window(mlx, data->x_size, data->y_size, "square");
	data->mlx = mlx;
	data->win = win;
	reset(data);
	printf(" ==> mlx : %s | data : %s\n", data->mlx, data->win);
	mlx_key_hook(win, my_key_funct, data);
	mlx_mouse_hook(data->win, my_mouse_funct, data);
	mlx_loop(mlx);
	return (0);
}
