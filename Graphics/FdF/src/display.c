/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:17:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/02 14:27:31 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			c1->x = (j - i) * 64 + 200;
			c1->y = (j + i) * 32 + 200 - map->tab[i][j];
			c1->color = 0xFFFFFF;
	//		c2->x = (j - i - 1) * 64 + 200;
	//		c2->y = (j + i + 1) * 32 + 200;
	//		ft_line(mlx, c1, c2);
			c2->x = (j + 1 - i) * 64 + 200;
			c2->y = (j + 1 + i) * 32 + 200 - map->tab[i][j + 1];
			ft_line(mlx, c1, c2);
	//		ft_fill_pixel(mlx, (j - i) * 64, (j + i) * 32, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
