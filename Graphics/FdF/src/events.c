/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/12/06 20:54:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_n_height(int key, t_stock *stock)
{
	if (key == 115 && stock->mlx->x_unit < 10000 && stock->mlx->y_unit < 5000
			&& stock->mlx->z_unit < 2500)
	{
		stock->mlx->x_unit += 2;
		stock->mlx->y_unit += 1;
		stock->mlx->z_unit += 0.5;
	}
	else if (key == 119 && stock->mlx->x_unit > 1 && stock->mlx->y_unit > 1
			&& stock->mlx->z_unit > -100)
	{
		stock->mlx->x_unit -= 2;
		stock->mlx->y_unit -= 1;
		stock->mlx->z_unit -= 0.5;
	}
	else if (key == 116 && stock->mlx->z_unit < 2500)
		stock->mlx->z_unit += 0.1;
	else if (key == 121 && stock->mlx->z_unit > -100)
		stock->mlx->z_unit -= 0.1;
}

void	ft_move(int key, t_stock *stock)
{
	if (key == 126 && stock->mlx->top_shift > -10000)
		stock->mlx->top_shift -= 10;
	else if (key == 125 && stock->mlx->top_shift < 10000)
		stock->mlx->top_shift += 10;
	else if (key == 123 && stock->mlx->left_shift > -10000)
		stock->mlx->left_shift -= 10;
	else if (key == 124 && stock->mlx->left_shift < 10000)
		stock->mlx->left_shift += 10;
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
	stock->mlx->width - 300, 100, 0xFFFFFF, "TAB              perspective");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 125, 0xFFFFFF, "PAGE UP / DOWN   height");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 150, 0xFFFFFF, "ARROWS           move");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 175, 0xFFFFFF, "HOME / END       zoom");
	mlx_string_put(stock->mlx->ptr, stock->mlx->win,
	stock->mlx->width - 300, 200, 0xFFFFFF, "NUMBERS          colors");
}

void	ft_reset(t_stock *stock)
{
	stock->mlx->x_unit = 32 - 4 * ft_smaller_units(stock->map);
	stock->mlx->y_unit = 16 - 2 * ft_smaller_units(stock->map);
	stock->mlx->z_unit = 8 - 1 * ft_smaller_units(stock->map);
	stock->mlx->top_shift = stock->mlx->y_unit
		+ stock->mlx->z_unit * ft_max_z(stock->map);
	stock->mlx->left_shift = stock->mlx->x_unit * stock->map->lines;
	stock->mlx->pers_choice = 1;
	stock->mlx->panel_choice = 0;
}

int		ft_key(int key, t_stock *stock)
{
	if (key == 53)
		exit(0);
	else if ((key >= 18 && key <= 21) || key == 23)
		stock->mlx->panel_choice = key == 23 ? 4 : key - 18;
	else if (key == 115 || key == 116 || key == 119 || key == 121)
		ft_zoom_n_height(key, stock);
	else if (key >= 123 && key <= 126)
		ft_move(key, stock);
	else if (key == 15)
		ft_reset(stock);
	else if (key == 48)
		stock->mlx->pers_choice = !stock->mlx->pers_choice;
	ft_bzero(stock->mlx->str,
			stock->mlx->width * stock->mlx->height * sizeof(int));
	ft_put_map_to_img(stock->mlx, stock->map);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->img, 0, 0);
	ft_tutorial(stock);
	return (0);
}
