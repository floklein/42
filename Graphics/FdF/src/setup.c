/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 00:08:08 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_setup(t_mlx *mlx)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

t_mlx	*ft_mlx_setup(int width, int height)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->width = width;
	mlx->height = height;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "fdf");
	return (mlx);
}
