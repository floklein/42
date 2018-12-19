/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:20:11 by flklein           #+#    #+#             */
/*   Updated: 2018/12/19 16:36:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_cube_helper(t_thread *t, t_coord c, t_complex cst)
{
	t_complex	n;
	t_complex	o;

	n.x = 1.5 * (c.x - t->mlx->width / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->width) + t->mlx->move_x + 0.5;
	n.y = (c.y - t->mlx->height / 2)
		/ (0.5 * t->mlx->zoom * t->mlx->height) + t->mlx->move_y;
	t->i = 0;
	while (t->i < t->mlx->iter)
	{
		o.x = n.x;
		o.y = n.y;
		n.x = o.x * o.x * o.x - 3 * o.x * o.y * o.y + cst.x;
		n.y = 3 * o.x * o.x * o.y - o.y * o.y * o.y + cst.y;
		if (n.x * n.x + n.y * n.y > 4)
			break ;
		t->i++;
	}
}

void		*ft_cube(void *threadv)
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
			ft_cube_helper(t, c, cst);
			ft_fill_pixel(t->mlx, c.x, c.y, ft_hsv_to_rgb(4 * t->i / 255.0, 1,
						t->i < t->mlx->iter, t->mlx->panel_choice));
			c.x++;
		}
		c.y++;
	}
	pthread_exit(NULL);
	return (NULL);
}
