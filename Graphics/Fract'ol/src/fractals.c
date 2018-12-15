/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:58:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/15 19:08:17 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_mlx *mlx)
{
	t_coord		c;
	t_complex	p;
	t_complex	new;
	t_complex	old;
	int			i;

	c.y = 0;
	while (c.y < mlx->height)
	{
		c.x = 0;
		while (c.x < mlx->width)
		{
			p.x = 1.5 * (c.x - mlx->width / 2) / (0.5 * mlx->zoom * mlx->width)
				+ mlx->move_x;
			p.y = (c.y - mlx->height / 2) / (0.5 * mlx->zoom * mlx->height)
				+ mlx->move_y;
			new.x = 0;
			new.y = 0;
			i = 0;
			while (i < mlx->iter)
			{
				old.x = new.x;
				old.y = new.y;
				new.x = old.x * old.x - old.y * old.y + p.x;
				new.y = 2 * old.x * old.y + p.y;
				if (new.x * new.x + new.y * new.y > 4)
					break ;
				i++;
			}
			c.color = ft_hsv_to_rgb(i / 255.0, 1, i < mlx->iter, mlx->panel_choice);
			ft_fill_pixel(mlx, c.x, c.y, c.color);
			c.x++;
		}
		c.y++;
	}
}

void	ft_julia(t_mlx *mlx)
{
	t_coord		c;
	t_complex	cst;
	t_complex	new;
	t_complex	old;
	int			i;

	cst.x = mlx->julia.x;
	cst.y = mlx->julia.y;
	c.y = 0;
	while (c.y < mlx->height)
	{
		c.x = 0;
		while (c.x < mlx->width)
		{
			new.x = 1.5 * (c.x - mlx->width / 2) / (0.5 * mlx->zoom * mlx->width)
				+ mlx->move_x;
			new.y = (c.y - mlx->height / 2) / (0.5 * mlx->zoom * mlx->height)
				+ mlx->move_y;
			i = 0;
			while (i < mlx->iter)
			{
				old.x = new.x;
				old.y = new.y;
				new.x = old.x * old.x - old.y * old.y + cst.x;
				new.y = 2 * old.x * old.y + cst.y;
				if (new.x * new.x + new.y * new.y > 4)
					break ;
				i++;
			}
			c.color = ft_hsv_to_rgb(i / 255.0, 1, i < mlx->iter, mlx->panel_choice);
			ft_fill_pixel(mlx, c.x, c.y, c.color);
			c.x++;
		}
		c.y++;
	}
}

void	ft_put_fractal_to_img(t_mlx *mlx)
{
	if (mlx->fractal == 0)
		ft_mandelbrot(mlx);
	else if (mlx->fractal == 1)
		ft_julia(mlx);
}
