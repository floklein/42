/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 17:12:34 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, t_stock *stock)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	ft_bzero(stock->mlx->str, stock->mlx->width * stock->mlx->height * sizeof(int));
	ft_put_map_to_img(stock->mlx, stock->map);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win,
			stock->mlx->img, 0, 0);
	return (0);
}
