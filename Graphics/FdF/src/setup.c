/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 21:03:37 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max_z(t_map *map)
{
	int		max;
	int		i;
	int		j;

	max = -2147483648;
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->tab[i][j] > max)
				max = map->tab[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

int		ft_smaller_units(t_map *map)
{
	if (map->lines >= 150 || map->columns >= 150)
		return (7);
	if (map->lines >= 100 || map->columns >= 100)
		return (6);
	if (map->lines >= 50 || map->columns >= 50)
		return (4);
	if (map->lines >= 25 || map->columns >= 25)
		return (2);
	return (0);
}

int		ft_smaller_window(t_map *map)
{
	if (map->lines <= 10 && map->columns <= 10)
		return (2);
	if (map->lines <= 24 && map->columns <= 24)
		return (1);
	return (0);
}

void	ft_img_setup(t_mlx *mlx)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

t_mlx	*ft_mlx_setup(t_map *map)
{
	t_mlx	*mlx;
	int		red_w;
	int		red_u;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	red_w = ft_smaller_window(map);
	mlx->width = 1920 - 600 * red_w;
	mlx->height = 1080 - 300 * red_w;
	red_u = ft_smaller_units(map);
	mlx->x_unit = 32 - 4 * red_u;
	mlx->y_unit = 16 - 2 * red_u;
	mlx->z_unit = 8 - 1 * red_u;
	mlx->top_shift = mlx->y_unit + mlx->z_unit * ft_max_z(map);
	mlx->left_shift = mlx->x_unit * map->lines;
	mlx->panel_choice = 0;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "fdf");
	return (mlx);
}
