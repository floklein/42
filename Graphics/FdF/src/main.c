/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 18:27:48 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putendl("./fdf <map_file>");
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;
	t_coord	*coord;
	int		i;
	int		j;

	if (ac != 2)
		return (ft_usage());
	if (!(map = ft_parse(av[1])))
		return (0);
	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (j < map->columns)
		{
			ft_putnbr(map->tab[i][j++]);
			j < map->columns - 1 ? ft_putchar('\t') : 0;
		}
		ft_putchar('\n');
		i++;
	}
	if (!(mlx = ft_mlx_setup(1200, 800)))
		return (0);
	ft_img_setup(mlx);
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	coord->x1 = 50;
	coord->y1 = 50;
	coord->x2 = 500;
	coord->y2 = 250;
	ft_line(mlx, coord, 0xFFFF00);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, &ft_key, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
