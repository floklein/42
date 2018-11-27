/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:49 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 18:46:02 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->data[x + mlx->width * y] = color;
}

void	ft_line(t_mlx *mlx, t_coord *coord, int color)
{
	int		dx;
	int		dy;
	int		e;

	e = coord->x2 - coord->x1;
	dx = e * 2;
	dy = (coord->y2 - coord->y1) * 2;
	while (coord->x1 <= coord->x2)
	{
		ft_fill_pixel(mlx, coord->x1, coord->y1, color);
		coord->x1++;
		if ((e -= dy) <= 0)
		{
			coord->y1++;
			e += dx;
		}
	}
}
