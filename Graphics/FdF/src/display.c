/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:17:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 16:52:09 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_img(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			ft_fill_pixel(mlx, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	ft_put_map_to_img(t_mlx *mlx, t_map *map)
{
	t_coord *c1;
	t_coord	*c2;
	int		i;
	int		j;

	if (!(c1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if (!(c2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			c1->x = (j - i) * mlx->x_unit + mlx->left_shift;
			c1->y = (j + i) * mlx->y_unit + mlx->top_shift
				- mlx->z_unit * map->tab[i][j];
			c1->color = map->tab[i][j] > 0 ? 0xFF0000 : 0xFFFFFF;
			if (i < map->lines - 1)
			{
				c2->x = (j - i - 1) * mlx->x_unit + mlx->left_shift;
				c2->y = (j + i + 1) * mlx->y_unit + mlx->top_shift
					- mlx->z_unit * map->tab[i + 1][j];
				c2->color = map->tab[i + 1][j] > 0 ? 0xFF0000 : 0xFFFFFF;
				ft_line(mlx, c1, c2);
			}
			if (j < map->columns - 1)
			{
				c2->x = (j + 1 - i) * mlx->x_unit + mlx->left_shift;
				c2->y = (j + 1 + i) * mlx->y_unit + mlx->top_shift
					- mlx->z_unit * map->tab[i][j + 1];
				c2->color = map->tab[i][j + 1] > 0 ? 0xFF0000 : 0xFFFFFF;
				ft_line(mlx, c1, c2);
			}
			j++;
		}
		i++;
	}
}
