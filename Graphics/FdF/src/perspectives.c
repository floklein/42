/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:17:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/06 16:16:33 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_para_helper(t_mlx *mlx, t_map *map, int i, int j)
{
	mlx->c1->x = (j - i) * mlx->x_unit + mlx->left_shift;
	mlx->c1->y = (i) * mlx->y_unit + mlx->top_shift
		- mlx->z_unit * map->tab[i][j];
	mlx->c1->color = ft_choose_color(map->tab[i][j], mlx);
	if (i < map->lines - 1)
	{
		mlx->c2->x = (j - i - 1) * mlx->x_unit + mlx->left_shift;
		mlx->c2->y = (i + 1) * mlx->y_unit + mlx->top_shift
			- mlx->z_unit * map->tab[i + 1][j];
		mlx->c2->color = ft_choose_color(map->tab[i + 1][j], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
	if (j < map->columns - 1)
	{
		mlx->c2->x = (j + 1 - i) * mlx->x_unit + mlx->left_shift;
		mlx->c2->y = (i) * mlx->y_unit + mlx->top_shift
			- mlx->z_unit * map->tab[i][j + 1];
		mlx->c2->color = ft_choose_color(map->tab[i][j + 1], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
}

void	ft_para(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	mlx->y_unit *= 2;
	if (!(mlx->c1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if (!(mlx->c2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			ft_para_helper(mlx, map, i, j);
			j++;
		}
		i++;
	}
	mlx->y_unit /= 2;
}

void	ft_iso_helper(t_mlx *mlx, t_map *map, int i, int j)
{
	mlx->c1->x = (j - i) * mlx->x_unit + mlx->left_shift;
	mlx->c1->y = (j + i) * mlx->y_unit + mlx->top_shift
		- mlx->z_unit * map->tab[i][j];
	mlx->c1->color = ft_choose_color(map->tab[i][j], mlx);
	if (i < map->lines - 1)
	{
		mlx->c2->x = (j - i - 1) * mlx->x_unit + mlx->left_shift;
		mlx->c2->y = (j + i + 1) * mlx->y_unit + mlx->top_shift
			- mlx->z_unit * map->tab[i + 1][j];
		mlx->c2->color = ft_choose_color(map->tab[i + 1][j], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
	if (j < map->columns - 1)
	{
		mlx->c2->x = (j + 1 - i) * mlx->x_unit + mlx->left_shift;
		mlx->c2->y = (j + 1 + i) * mlx->y_unit + mlx->top_shift
			- mlx->z_unit * map->tab[i][j + 1];
		mlx->c2->color = ft_choose_color(map->tab[i][j + 1], mlx);
		ft_line(mlx, mlx->c1, mlx->c2);
	}
}

void	ft_iso(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	if (!(mlx->c1 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	if (!(mlx->c2 = (t_coord *)malloc(sizeof(t_coord))))
		return ;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			ft_iso_helper(mlx, map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_put_map_to_img(t_mlx *mlx, t_map *map)
{
	if (mlx->pers_choice)
		ft_iso(mlx, map);
	else
		ft_para(mlx, map);
}
