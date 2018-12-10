/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/12/10 18:47:59 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_title(char *title)
{
	int		i;

	while (ft_strchr(title, '/'))
		title = ft_strchr(title, '/') + 1;
	i = ft_strlen(title);
	while (i && title[i] == '.' ? title[i] = '\0' : 1)
		i--;
	return (title);
}

int		ft_usage(void)
{
	ft_putendl("usage: ./fractol <fractal name>");
	return (0);
}

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_stock	*stock;

	if (ac != 2)
		return (ft_usage());
	if (!(mlx = ft_mlx_setup(ft_title(av[1]))))
		return (0);
	ft_put_fractal_to_img(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	stock->mlx = mlx;
	mlx_hook(mlx->win, 2, (1L << 0), &ft_key, stock);
	mlx_hook(mlx->win, 17, (1L << 17), &ft_close, NULL);
	ft_tutorial(stock);
	mlx_loop(mlx->ptr);
	return (0);
}
