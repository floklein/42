/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:58:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/19 16:10:31 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandelbrot_helper(t_thread *t, t_coord c)
{
	t_complex	p;
	t_complex	new;
	t_complex	old;

	p.x = 1.5 * (c.x - t->mlx->width / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->width) + t->mlx->move_x;
	p.y = (c.y - t->mlx->height / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->height) + t->mlx->move_y;
	new.x = 0;
	new.y = 0;
	t->i = 0;
	while (t->i < t->mlx->iter)
	{
		old.x = new.x;
		old.y = new.y;
		new.x = old.x * old.x - old.y * old.y + p.x;
		new.y = 2 * old.x * old.y + p.y;
		if (new.x * new.x + new.y * new.y > 4)
			break ;
		t->i++;
	}
}

void		*ft_mandelbrot(void *threadv)
{
	t_coord		c;
	t_thread	*t;

	t = (t_thread *)threadv;
	c.y = t->n * t->mlx->height / THREADS;
	t->max = (t->n + 1) * t->mlx->height / THREADS;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
			ft_mandelbrot_helper(t, c);
			ft_fill_pixel(t->mlx, c.x, c.y, ft_hsv_to_rgb(t->i / 255.0, 1,
						t->i < t->mlx->iter, t->mlx->panel_choice));
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

static void	ft_julia_helper(t_thread *t, t_coord c, t_complex cst)
{
	t_complex	new;
	t_complex	old;

	new.x = 1.5 * (c.x - t->mlx->width / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->width) + t->mlx->move_x + 0.5;
	new.y = (c.y - t->mlx->height / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->height) + t->mlx->move_y;
	t->i = 0;
	while (t->i < t->mlx->iter)
	{
		old.x = new.x;
		old.y = new.y;
		new.x = old.x * old.x - old.y * old.y + cst.x;
		new.y = 2 * old.x * old.y + cst.y;
		if (new.x * new.x + new.y * new.y > 4)
			break ;
		t->i++;
	}
}

void		*ft_julia(void *threadv)
{
	t_coord		c;
	t_complex	cst;
	t_thread	*t;

	t = (t_thread *)threadv;
	cst.x = t->mlx->julia.x;
	cst.y = t->mlx->julia.y;
	c.y = t->n * t->mlx->height / THREADS;
	t->max = (t->n + 1) * t->mlx->height / THREADS;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
			ft_julia_helper(t, c, cst);
			ft_fill_pixel(t->mlx, c.x, c.y, ft_hsv_to_rgb(t->i / 255.0, 1,
						t->i < t->mlx->iter, t->mlx->panel_choice));
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}
