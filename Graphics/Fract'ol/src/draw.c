/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:42:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/18 18:48:32 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_htr_helper(t_c *c, double v1, double v2, double v3)
{
	c->r = v1;
	c->g = v2;
	c->b = v3;
}

int			ft_hsv_to_rgb(double h, double s, double v, int panel)
{
	t_c		c;

	c.i = (int)(h * 6);
	c.f = h * 6 - c.i;
	c.p = v * (1 - s);
	c.q = v * (1 - c.f * s);
	c.t = v * (1 - (1 - c.f) * s);
	if (c.i % 6 == 0)
		ft_htr_helper(&c, v, c.t, c.p);
	else if (c.i % 6 == 1)
		ft_htr_helper(&c, c.q, v, c.p);
	else if (c.i % 6 == 2)
		ft_htr_helper(&c, c.p, v, c.t);
	else if (c.i % 6 == 3)
		ft_htr_helper(&c, c.p, c.q, v);
	else if (c.i % 6 == 4)
		ft_htr_helper(&c, c.t, c.p, v);
	else
		ft_htr_helper(&c, v, c.p, c.q);
	if (panel == 0)
		return (c.r * 0xFF0000 + c.g * 0x00FF00 + c.b * 0x0000FF);
	else if (panel == 1)
		return (c.b * 0xFF0000 + c.r * 0x00FF00 + c.g * 0x0000FF);
	else
		return (c.g * 0xFF0000 + c.b * 0x00FF00 + c.r * 0x0000FF);
}

void		ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}

void	ft_put_fractal_to_img(t_stock *stock)
{
	t_thread	th_tab[THREADS];
	void		*f;
	int			i;

	if (stock->mlx->fractal == 0)
		f = ft_mandelbrot;
	else if (stock->mlx->fractal == 1)
		f = ft_julia;
	else if (stock->mlx->fractal == 2)
		f = ft_burningship;
	else if (stock->mlx->fractal == 3)
		f = ft_tricorn;
	else if (stock->mlx->fractal == 4)
		f = ft_thunder;
	else if (stock->mlx->fractal == 5)
		f = ft_bubble;
	else if (stock->mlx->fractal == 6)
		f = ft_shell;
	else if (stock->mlx->fractal == 7)
		f = ft_feather;
	else if (stock->mlx->fractal == 8)
		f = ft_cube;
	else if (stock->mlx->fractal == 9)
		f = ft_test;
	i = 0;
	while (i < THREADS)
	{
		th_tab[i].n = i;
		th_tab[i].mlx = stock->mlx;
		pthread_create(&(th_tab[i].id), NULL, f, (void *)&(th_tab[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(th_tab[i++].id, NULL);
}
