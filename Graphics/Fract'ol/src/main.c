/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/17 21:45:52 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_usage(void)
{
	ft_putendl("usage: ./fractol <fractal name>");
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_stock	*stock;

	if (ac != 2)
		return (ft_usage());
	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	if (!(stock->mlx = ft_mlx_setup(av[1])))
		return (0);
	ft_put_fractal_to_img(stock);
	mlx_put_image_to_window(stock->mlx->ptr, stock->mlx->win, stock->mlx->img,
			0, 0);
	mlx_hook(stock->mlx->win, 2, (1L << 0), &ft_key, stock);
	mlx_hook(stock->mlx->win, 6, (1L << 6), &ft_mouse_event, stock);
	mlx_hook(stock->mlx->win, 4, (1L << 2), &ft_mouse_zoom, stock);
	mlx_hook(stock->mlx->win, 17, (1L << 17), &ft_close, NULL);
	ft_tutorial(stock);
	mlx_loop(stock->mlx->ptr);
	return (0);
}
