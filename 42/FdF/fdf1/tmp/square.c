/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:23:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 18:27:18 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	square(t_data *data, int color)
{
	int	i = data->x - 1;
	int	j = data->y - 1;

	while (i++ <= data->x2 + 1)
	{
		while (j++ <= data->y2 + 1)
			mlx_pixel_put(data->mlx, data->win, i, j, color);
		j = data->y - 1;
	}
	return (0);
}

int	move(t_data *data, int keycode)
{
	if (keycode == 126)
	{
		square(data, 0x00000000);
		data->y -= 5;
		data->y2 -= 5;
		square(data, 0x00FFFFFF);
	}
	if (keycode == 125)
	{
		square(data, 0x00000000);
		data->y += 5;
		data->y2 += 5;
		square(data, 0x00FFFFFF);
	}
	if (keycode == 123)
	{
		square(data, 0x00000000);
		data->x -= 5;
		data->x2 -= 5;
		square(data, 0x00FFFFFF);
	}
	if (keycode == 124)
	{
		square(data, 0x00000000);
		data->x += 5;
		data->x2 += 5;
		square(data, 0x00FFFFFF);
	}
	return (0);
}

int	my_key_funct(int keycode, t_data *data)
{
	printf("key event %d ¬\n", keycode);
	printf("mlx : %s | data : %s\n", data->mlx, data->win);
	if (keycode == 15)
	{
		square(data, 0x00000000);
		data->x = 350;
		data->y = 350;
		data->x2 = 450;
		data->y2 = 450;
		square(data, 0x00FFFFFF);
	}
	move(data, keycode);
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
	data->x_size = 800;
	data->y_size = 800;
	win = mlx_new_window(mlx, data->x_size, data->y_size, "square");
	data->mlx = mlx;
	data->win = win;
	data->x = 350;
	data->y = 350;
	data->x2 = 450;
	data->y2 = 450;
	printf(" ==> mlx : %s | data : %s\n", data->mlx, data->win);
	mlx_key_hook(win, my_key_funct, data);
	mlx_loop(mlx);
	return (0);
}
