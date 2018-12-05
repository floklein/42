/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by flklein           #+#    #+#             */
/*   Updated: 2018/12/05 21:10:13 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_coord
{
	double	x;
	double	y;
	int		color;
}				t_coord;

typedef struct	s_map
{
	int		**tab;
	int		columns;
	int		lines;
}				t_map;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	void	*img;
	int		*str;
	int		x_unit;
	int		y_unit;
	int		z_unit;
	int		top_shift;
	int		left_shift;
	int		panel_choice;
	int		panel[5][5];
}				t_mlx;

typedef struct	s_stock
{
	t_mlx	*mlx;
	t_map	*map;
}				t_stock;

int				ft_count_values(char *str);
int				ft_key(int key, t_stock *stock);
int				ft_usage(void);
int				main(int ac, char **av);
t_map			*ft_parse(char *file);
t_mlx			*ft_mlx_setup(t_map *map);
void			ft_display_map(t_map *map);
void			ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_img_setup(t_mlx *mlx);
void			ft_panel_setup(t_mlx *mlx);
void			ft_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2);
void			ft_put_map_to_img(t_mlx *mlx, t_map *map);
void			ft_clear_img(t_mlx *mlx);

#endif
