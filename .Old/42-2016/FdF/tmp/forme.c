/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:47:22 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 16:30:05 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	main()
{
	void *mlx;
	void *win;
	int x = 99;
	int y = 99;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "forme");
	while (x++ <= 301)
	{
		while (y++ <= 301)
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		y = 99;
	}
	mlx_loop(mlx);
}
