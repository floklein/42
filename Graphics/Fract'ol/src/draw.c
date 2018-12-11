/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:42:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/11 16:21:33 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_hsv_to_rgb(double h, double s, double v, int panel)
{
	double	r;
	double	g;
	double	b;
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)(h * 6);
	f = h * 6 - i;
	p = v * (1 - s);
	q = v * (1 - f * s);
	t = v * (1 - (1 - f) * s);
	if (i % 6 == 0)
	{
		r = v;
		g = t;
		b = p;
	}
	else if (i % 6 == 1)
	{
		r = q;
		g = v;
		b = p;
	}
	else if (i % 6 == 2)
	{
		r = p;
		g = v;
		b = t;
	}
	else if (i % 6 == 3)
	{
		r = p;
		g = q;
		b = v;
	}
	else if (i % 6 == 4)
	{
		r = t;
		g = p;
		b = v;
	}
	else
	{
		r = v;
		g = p;
		b = q;
	}
	if (panel == 0)
		return (r * 0xFF0000 + g * 0x00FF00 + b * 0x0000FF);
	else if (panel == 1)
		return (b * 0xFF0000 + r * 0x00FF00 + g * 0x0000FF);
	else
		return (g * 0xFF0000 + b * 0x00FF00 + r * 0x0000FF);
}

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}
