/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 18:10:22 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_stock *stock)
{
	if (key == 115 && stock->mlx->x_unit < 100 && stock->mlx->y_unit < 50
			&& stock->mlx->z_unit < 25)
	{
		stock->mlx->x_unit += 4;
		stock->mlx->y_unit += 2;
		stock->mlx->z_unit += 1;
	}
	else if (key == 119 && stock->mlx->x_unit > 0 && stock->mlx->y_unit > 0
			&& stock->mlx->z_unit > 0)
	{
		stock->mlx->x_unit -= 4;
		stock->mlx->y_unit -= 2;
		stock->mlx->z_unit -= 1;
	}
}

void	ft_height(int key, t_stock *stock)
{
	if (key == 121 && stock->mlx->z_unit > -30)
		stock->mlx->z_unit -= 1;
	else if (key == 116 && stock->mlx->z_unit < 30)
		stock->mlx->z_unit += 1;
}

void	ft_move(int key, t_stock *stock)
{
	if (key == 126)
		stock->mlx->top_shift -= 10;
	if (key == 125)
		stock->mlx->top_shift += 10;
	if (key == 123)
		stock->mlx->left_shift -= 10;
	if (key == 124)
		stock->mlx->left_shift += 10;
}

int		ft_key(int key, t_stock *stock)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	ft_zoom(key, stock);
	ft_height(key, stock);
	ft_move(key, stock);
	ft_bzero(stock->mlx->str,
			stock->mlx->width * stock->mlx->height * sizeof(int));
	ft_put_map_to_img(stock->mlx, stock->map);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->img, 0, 0);
	return (0);
}
