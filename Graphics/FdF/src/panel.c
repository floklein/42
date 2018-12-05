/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:36:12 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 21:17:40 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_panel_setup(t_mlx *mlx)
{
	mlx->panel[0][0] = 0xFFFFFF;
	mlx->panel[0][1] = 0xFFFFFF;
	mlx->panel[0][2] = 0xFFFFFF;
	mlx->panel[0][3] = 0xFFFFFF;
	mlx->panel[0][4] = 0xFFFFFF;
	mlx->panel[1][0] = 0x0029AF;
	mlx->panel[1][1] = 0x9BFF54;
	mlx->panel[1][2] = 0x1F7C00;
	mlx->panel[1][3] = 0x7C4A00;
	mlx->panel[1][4] = 0xF4F4F4;
	mlx->panel[2][0] = 0xFF0000;
	mlx->panel[2][1] = 0x00FF00;
	mlx->panel[2][2] = 0x0000FF;
	mlx->panel[2][3] = 0xFFFF00;
	mlx->panel[2][4] = 0x00FFFF;
	mlx->panel[3][0] = 0xFFF5BA;
	mlx->panel[3][1] = 0xBFFCC6;
	mlx->panel[3][2] = 0xA79AFF;
	mlx->panel[3][3] = 0xFFABAB;
	mlx->panel[3][4] = 0x85E3FF;
	mlx->panel[4][0] = 0x393E46;
	mlx->panel[4][1] = 0x00ADB5;
	mlx->panel[4][2] = 0xFFF4E0;
	mlx->panel[4][3] = 0xF8B500;
	mlx->panel[4][4] = 0xFC3C3C;
}
