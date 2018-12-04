/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/04 15:51:20 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putendl("usage: ./fdf <map_file>");
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;

	if (ac != 2)
		return (ft_usage());
	if (!(map = ft_parse(av[1])))
		return (0);
	ft_display_map(map);
	if (!(mlx = ft_mlx_setup(map)))
		return (0);
	ft_img_setup(mlx);
	ft_put_map_to_img(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, &ft_key, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
