/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:58:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/17 18:46:47 by flklein          ###   ########.fr       */
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
	c.y = t->n * t->mlx->height / 8;
	t->max = (t->n + 1) * t->mlx->height / 8;
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
	c.y = t->n * t->mlx->height / 8;;
	t->max = (t->n + 1) * t->mlx->height / 8;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
			new.x = 1.5 * (c.x - t->mlx->width / 2)
				/ (0.5 * t->mlx->zoom * t->mlx->width) + t->mlx->move_x;
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

void	ft_put_fractal_to_img(t_stock *stock)
{
	t_thread	th_tab[8];
	int			i;

	i = 0;
	if (stock->mlx->fractal == 0)
		while (i < 8)
		{
			th_tab[i].n = i;
			th_tab[i].mlx = stock->mlx;
			pthread_create(&(th_tab[i].id), NULL, ft_mandelbrot,
					(void *)&(th_tab[i]));
			i++;
		}
	else if (stock->mlx->fractal == 1)
		while (i < 8)
		{
			th_tab[i].n = i;
			th_tab[i].mlx = stock->mlx;
			pthread_create(&(th_tab[i].id), NULL, ft_julia,
					(void *)&(th_tab[i]));
			i++;
		}
	i = 0;
	while (i < 8)
		pthread_join(th_tab[i++].id, NULL);
}
