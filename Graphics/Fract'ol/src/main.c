/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/18 18:48:13 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_parse(char *file)
{
	if (ft_strequ(file, "mandelbrot"))
		return (0);
	else if (ft_strequ(file, "julia"))
		return (1);
	else if (ft_strequ(file, "burningship"))
		return (2);
	else if (ft_strequ(file, "tricorn"))
		return (3);
	else if (ft_strequ(file, "thunder"))
		return (4);
	else if (ft_strequ(file, "bubble"))
		return (5);
	else if (ft_strequ(file, "shell"))
		return (6);
	else if (ft_strequ(file, "feather"))
		return (7);
	else if (ft_strequ(file, "cube"))
		return (8);
	else if (ft_strequ(file, "test"))
		return (9);
	return (-1);
}

t_mlx	*ft_mlx_setup(char *title)
{
	t_mlx	*mlx;
	int		bpp;
	int		s_l;
	int		endian;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if ((mlx->fractal = ft_parse(title)) == -1)
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->width = 1280;
	mlx->height = 720;
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
	mlx->zoom = 1;
	mlx->move_x = -0.5;
	mlx->move_y = 0;
	mlx->iter = 100;
	mlx->panel_choice = 0;
	mlx->julia.x = -0.7;
	mlx->julia.y = 0.27015;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, title);
	return (mlx);
}

int		ft_usage(void)
{
	ft_putendl("\
usage: ./fractol <fractal name>\
\nfractals: mandelbrot, julia, burningship, tricorn, thunder, bubble,\
shell, feather");
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
