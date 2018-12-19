/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:42:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/19 15:17:21 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_htr_helper(t_color *c, double v1, double v2, double v3)
{
	c->r = v1;
	c->g = v2;
	c->b = v3;
}

int			ft_hsv_to_rgb(double h, double s, double v, int panel)
{
	t_color		c;

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

void		ft_put_fractal_to_img(t_stock *stock)
{
	t_thread	th_tab[THREADS];
	void		*f;
	int			i;

	stock->mlx->fractal == 0 ? f = ft_mandelbrot : 0;
	stock->mlx->fractal == 1 ? f = ft_julia : 0;
	stock->mlx->fractal == 2 ? f = ft_burningship : 0;
	stock->mlx->fractal == 3 ? f = ft_tricorn : 0;
	stock->mlx->fractal == 4 ? f = ft_thunder : 0;
	stock->mlx->fractal == 5 ? f = ft_bubble : 0;
	stock->mlx->fractal == 6 ? f = ft_shell : 0;
	stock->mlx->fractal == 7 ? f = ft_feather : 0;
	stock->mlx->fractal == 8 ? f = ft_cube : 0;
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
