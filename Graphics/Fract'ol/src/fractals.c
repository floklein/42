/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:58:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/18 13:52:41 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_mandelbrot(void *threadv)
{
	t_coord		c;
	t_complex	p;
	t_complex	new;
	t_complex	old;
	t_thread	*t;

	t = (t_thread *)threadv;
	c.y = t->n * t->mlx->height / THREADS;
	t->max = (t->n + 1) * t->mlx->height / THREADS;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
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
			c.color = ft_hsv_to_rgb(t->i / 255.0, 1, t->i < t->mlx->iter,
					t->mlx->panel_choice);
			ft_fill_pixel(t->mlx, c.x, c.y, c.color);
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*ft_julia(void *threadv)
{
	t_coord		c;
	t_complex	cst;
	t_complex	new;
	t_complex	old;
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
			c.color = ft_hsv_to_rgb(t->i / 255.0, 1, t->i < t->mlx->iter,
					t->mlx->panel_choice);
			ft_fill_pixel(t->mlx, c.x, c.y, c.color);
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

void	*ft_burningship(void *threadv)
{
	t_coord		c;
	t_complex	z;
	t_complex	s;
	t_complex	tmp;
	t_thread	*t;

	t = (t_thread *)threadv;
	c.y = t->n * t->mlx->height / THREADS;
	t->max = (t->n + 1) * t->mlx->height / THREADS;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
			s.x = 3.5 * (c.x - t->mlx->width / 2)
				/ (t->mlx->width * t->mlx->zoom) + t->mlx->move_x;
			s.y = 2 * (c.y - t->mlx->height / 2)
				/ (t->mlx->height * t->mlx->zoom) - 0.5 + t->mlx->move_y;
			z.x = s.x;
			z.y = s.y;
			t->i = 0;
			while (z.x * z.x + z.y * z.y < 4 && t->i < t->mlx->iter)
			{
				tmp.x = z.x * z.x - z.y * z.y + s.x;
				z.y = fabs(2 * z.x * z.y) + s.y;
				z.x = fabs(tmp.x);
				t->i++;
			}
			c.color = ft_hsv_to_rgb(t->i / 255.0, 1, t->i < t->mlx->iter,
					t->mlx->panel_choice);
			ft_fill_pixel(t->mlx, c.x, c.y, c.color);
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
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
