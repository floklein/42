/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/12/15 15:31:14 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_n_iter(int key, t_stock *stock)
{
	if (key == 115 || key == 27)
		stock->mlx->zoom *= 2;
	else if (key == 119)
		stock->mlx->zoom /= 2;
	else if (key == 116 || key == 33)
		stock->mlx->iter += 100;
	else if (key == 121 && stock->mlx->iter > 100)
		stock->mlx->iter -= 100;
}

void	ft_move(int key, t_stock *stock)
{
	if (key == 126 && stock->mlx->move_y > -10000)
		stock->mlx->move_y += 0.05 / stock->mlx->zoom;
	else if (key == 125 && stock->mlx->move_y < 10000)
		stock->mlx-> move_y -= 0.05 / stock->mlx->zoom;
	else if (key == 123 && stock->mlx->move_x > -10000)
		stock->mlx->move_x += 0.05 / stock->mlx->zoom;
	else if (key == 124 && stock->mlx->move_x < 10000)
		stock->mlx->move_x -= 0.05 / stock->mlx->zoom;
}

void	ft_tutorial(t_stock *stock)
{
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 25, 0xFFFFFF, "        How to?");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 50, 0xFFFFFF, "ESC              quit");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 75, 0xFFFFFF, "R                reset");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 100, 0xFFFFFF, "TAB              next fractal");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 125, 0xFFFFFF, "PAGE UP / DOWN   iterations");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 150, 0xFFFFFF, "ARROWS           move");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->width - 300, 175, 0xFFFFFF, "HOME / END       zoom");
}

void	ft_reset(t_stock *stock)
{
	stock->mlx->zoom = 1;
	stock->mlx->move_x = -0.5;
	stock->mlx->move_y = 0;
	stock->mlx->iter = 100;
}

int		ft_key(int key, t_stock *stock)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	else if (key == 15)
		ft_reset(stock);
	else if (key >= 18 && key <= 20)
		stock->mlx->panel_choice = key - 18;
	else if (key == 48)
		stock->mlx->fractal = (stock->mlx->fractal + 1) % 3;
	ft_zoom_n_iter(key, stock);
	ft_move(key, stock);
	ft_bzero(stock->mlx->str,
			stock->mlx->width * stock->mlx->height * sizeof(int));
	ft_put_fractal_to_img(stock->mlx);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->img, 0, 0);
	ft_tutorial(stock);
	return (0);
}
