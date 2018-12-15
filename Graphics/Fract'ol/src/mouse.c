/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:21:14 by flklein           #+#    #+#             */
/*   Updated: 2018/12/15 14:38:27 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_zoom(int key, int x, int y, t_stock *stock)
{
	if (x > 0 && x < stock->mlx->width && y > 0 && y < stock->mlx->width)
	{
		if (key == 4)
		{
			stock->mlx->zoom *= 1.5;
		}
		else if (key == 5)
		{
			stock->mlx->zoom /= 1.5;
		}
	}
	ft_bzero(stock->mlx->str,
			stock->mlx->width * stock->mlx->height * sizeof(int));
	ft_put_fractal_to_img(stock->mlx);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win, stock->mlx->img,
			0, 0);
	ft_tutorial(stock);
	return (0);
}
