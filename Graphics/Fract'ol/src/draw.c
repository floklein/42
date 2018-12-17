/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:42:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/17 21:43:47 by flklein          ###   ########.fr       */
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
