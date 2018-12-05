/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 21:28:12 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_stock *stock)
{
	if (key == 115 && stock->mlx->x_unit < 10000 && stock->mlx->y_unit < 5000
			&& stock->mlx->z_unit < 2500)
	{
		stock->mlx->x_unit += 4;
		stock->mlx->y_unit += 2;
		stock->mlx->z_unit += 1;
	}
	else if (key == 119 && stock->mlx->x_unit > 1 && stock->mlx->y_unit > 1
			&& stock->mlx->z_unit > 1)
	{
		stock->mlx->x_unit -= 4;
		stock->mlx->y_unit -= 2;
		stock->mlx->z_unit -= 1;
	}
}

void	ft_height(int key, t_stock *stock)
{
	if (key == 116 && stock->mlx->z_unit < 100)
		stock->mlx->z_unit += 1;
	else if (key == 121 && stock->mlx->z_unit > -100)
		stock->mlx->z_unit -= 1;
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

void	ft_tutorial(t_stock *stock)
{
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			50, stock->mlx->width - 200, 0xFFFFFF, "How to?");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			100, stock->mlx->width - 200, 0xFFFFFF, "ESC to quit");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			150, stock->mlx->width - 200, 0xFFFFFF, "ARROWS to move");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			200, stock->mlx->width - 200, 0xFFFFFF, "HOME / END to zoom");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			250, stock->mlx->width - 200, 0xFFFFFF, "PAGE UP / DOWN for height");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			300, stock->mlx->width - 200, 0xFFFFFF, "for colors");
}

int		ft_key(int key, t_stock *stock)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	else if ((key >= 18 && key <= 21) || key == 23)
		stock->mlx->panel_choice = key == 23 ? 4 : key - 18;
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
