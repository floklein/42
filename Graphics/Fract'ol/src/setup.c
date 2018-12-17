/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/17 21:03:27 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_parse(char *file)
{
	if (ft_strequ(file, "mandelbrot"))
		return (0);
	if (ft_strequ(file, "julia"))
		return (1);
	if (ft_strequ(file, "burningship"))
		return (2);
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
