/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:58:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/15 22:46:35 by flklein          ###   ########.fr       */
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

typedef struct	s_line
{
	int		lenght;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;
	double	mix;
}				t_line;

void	ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs(c2->x - c1->x) >= ft_abs(c2->y - c1->y))
		line->lenght = ft_abs(c2->x - c1->x);
	else
		line->lenght = ft_abs(c2->y - c1->y);
	line->dx = (c2->x - c1->x) / line->lenght;
	line->dy = (c2->y - c1->y) / line->lenght;
	line->x = c1->x + 0.5;
	line->y = c1->y + 0.5;
	line->i = 1;
	while (line->i <= line->lenght && line->x < mlx->width
			&& line->y < mlx->height)
	{
		line->mix = line->i / (double)line->lenght;
		ft_fill_pixel(mlx, (int)line->x, (int)line->y,
				c1->color * (1 - line->mix) + c2->color * line->mix);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}

#include <math.h>

void	ft_koch(t_mlx *mlx, int x1, int y1, int x2, int y2, int it)
{
	float angle = 60*M_PI/180;
	int x3 = (2*x1+x2)/3;
	int y3 = (2*y1+y2)/3;

	int x4 = (x1+2*x2)/3;
	int y4 = (y1+2*y2)/3;

	int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);
	t_coord	c1;
	t_coord	c2;

	if(it > 0)
	{
		ft_koch(mlx, x1, y1, x3, y3, it-1);
		ft_koch(mlx, x3, y3, x, y, it-1);
		ft_koch(mlx, x, y, x4, y4, it-1);
		ft_koch(mlx, x4, y4, x2, y2, it-1);
	}
	else
	{
		c1.x = x1;
		c1.y = y1;
		c2.x = x3;
		c2.y = y3;
		ft_line(mlx, &c1, &c2);
		c1.x = x3;
		c1.y = y3;
		c2.x = x;
		c2.y = y;
		ft_line(mlx, &c1, &c2);
		c1.x = x;
		c1.y = y;
		c2.x = x4;
		c2.y = y4;
		ft_line(mlx, &c1, &c2);
		c1.x = x4;
		c1.y = y4;
		c2.x = x2;
		c2.y = y2;
		ft_line(mlx, &c1, &c2);
	}
}

void	ft_put_fractal_to_img(t_mlx *mlx)
{
	if (mlx->fractal == 0)
		ft_mandelbrot(mlx);
	else if (mlx->fractal == 1)
		ft_julia(mlx);
	else if (mlx->fractal == 2)
		ft_koch(mlx, 0, 0, 1280, 720, 4);
}
