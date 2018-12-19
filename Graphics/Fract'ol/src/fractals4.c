/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:12 by flklein           #+#    #+#             */
/*   Updated: 2018/12/19 16:34:54 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_bubble_helper(t_thread *t, t_coord c, t_complex cst)
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

void		*ft_bubble(void *threadv)
{
	t_coord		c;
	t_complex	cst;
	t_thread	*t;

	t = (t_thread *)threadv;
	cst.x = -1.25;
	cst.y = 0;
	c.y = t->n * t->mlx->height / THREADS;
	t->max = (t->n + 1) * t->mlx->height / THREADS;
	while (c.y < t->max)
	{
		c.x = 0;
		while (c.x < t->mlx->width)
		{
			ft_bubble_helper(t, c, cst);
			ft_fill_pixel(t->mlx, c.x, c.y, ft_hsv_to_rgb(t->i / 255.0, 1,
						t->i < t->mlx->iter, t->mlx->panel_choice));
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

static void	ft_burningship_helper(t_thread *t, t_coord c)
{
	t_complex	z;
	t_complex	s;
	t_complex	tmp;

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
}

void		*ft_burningship(void *threadv)
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
			ft_burningship_helper(t, c);
			ft_fill_pixel(t->mlx, c.x, c.y, ft_hsv_to_rgb(t->i / 255.0, 1,
						t->i < t->mlx->iter, t->mlx->panel_choice));
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}
