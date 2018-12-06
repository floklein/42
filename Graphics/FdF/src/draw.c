/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:42:49 by flklein           #+#    #+#             */
/*   Updated: 2018/12/06 21:16:31 by flklein          ###   ########.fr       */
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

int		ft_choose_color(int alt, t_mlx *mlx)
{
	if (alt <= 0)
		return (mlx->panel[mlx->panel_choice][0]);
	else if (alt <= 10)
		return (mlx->panel[mlx->panel_choice][1]);
	else if (alt <= 20)
		return (mlx->panel[mlx->panel_choice][2]);
	else if (alt <= 30)
		return (mlx->panel[mlx->panel_choice][3]);
	else
		return (mlx->panel[mlx->panel_choice][4]);
}

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < mlx->width && y < mlx->height)
		mlx->str[x + mlx->width * y] = color;
}

void	ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2)
{
	t_line	*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return ;
	if (ft_abs(c2->x - c1->x) >= ft_abs(c2->y - c1->y))
		line->lenght = ft_abs(c2->x - c1->x);
	else
		line->lenght = ft_abs(c2->y - c1->y);
	line->dx = (c2->x - c1->x) / line->lenght;
	line->dy = (c2->y - c1->y) / line->lenght;
	line->x = c1->x + 0.5;
	line->y = c1->y + 0.5;
	line->i = 1;
	while (line->i <= line->lenght && line->x < mlx->width
			&& line->y < mlx->height)
	{
		line->mix = line->i / (double)line->lenght;
		ft_fill_pixel(mlx, (int)line->x, (int)line->y,
				c1->color * (1 - line->mix) + c2->color * line->mix);
		line->x += line->dx;
		line->y += line->dy;
		line->i++;
	}
	free(line);
}
