/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 16:48:48 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}
/*
   void	ft_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2)
   {
   int		dx;
   int		dy;
   int		e;

   e = coord2->x - coord1->x;
   dx = e * 2;
   dy = (coord2->y - coord1->y) * 2;
   while (coord1->x <= coord2->x)
   {
   ft_fill_pixel(mlx, coord1->x, coord1->y, coord1->color);
   coord1->x++;
   if ((e -= dy) <= 0)
   {
   coord1->y++;
   e += dx;
   }
   }
   }*/

#include <stdio.h>

void	ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2)
{
	int		lenght;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;
	double	mix;

	if (ft_abs(c2->x - c1->x) >= ft_abs(c2->y - c1->y))
		lenght =  ft_abs(c2->x - c1->x);
	else
		lenght = ft_abs(c2->y - c1->y);
	dx = (c2->x - c1->x) / lenght;
	dy = (c2->y - c1->y) / lenght;
	x = c1->x + 0.5;
	y = c1->y + 0.5;
	i = 1;
	while (i <= lenght && x < mlx->width && y < mlx->height)
	{
		mix = i / (double)lenght;
		ft_fill_pixel(mlx, (int)x, (int)y,
				c1->color * (1 - mix) + c2->color * mix);
		x += dx;
		y += dy;
		i++;
	}
}
