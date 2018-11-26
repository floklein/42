/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 00:34:51 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(void)
{
	t_mlx	*mlx;
//	int		x;
//	int		y;

	mlx = ft_mlx_setup(1200, 800);
	ft_img_setup(mlx);
//	x = 0;
//	while (++x < mlx->width)
//	{
//		y = 0;
//		while (++y < mlx->height)
//		{
//			if (y % 20 < 10)
//				ft_fill_pixel(mlx, x, y, x % 20 < 10 ? 0xFF0000 : 0x00FF00);
//			else
//				ft_fill_pixel(mlx, x, y, x % 20 < 10 ? 0x0000FF : 0x0F0F0F);
//		}
//	}
	ft_line(mlx, 50, 50, 1000, 800);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, &ft_key, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
