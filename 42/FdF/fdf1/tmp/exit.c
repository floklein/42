/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:23:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 16:37:28 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "exit");
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
}
