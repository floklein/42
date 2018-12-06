/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by flklein           #+#    #+#             */
/*   Updated: 2018/12/06 21:26:01 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_coord
{
	double	x;
	double	y;
	int		color;
}				t_coord;

typedef struct	s_line
{
	int		lenght;
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		i;
	double	mix;
}				t_line;

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
	double	z_unit;
	int		top_shift;
	int		left_shift;
	int		pers_choice;
	int		panel_choice;
	int		panel[5][5];
	t_coord	*c1;
	t_coord	*c2;
}				t_mlx;

typedef struct	s_stock
{
	t_mlx	*mlx;
	t_map	*map;
}				t_stock;

char			*ft_title(char *title);
int				ft_choose_color(int alt, t_mlx *mlx);
int				ft_close(void);
int				ft_count_values(char *str);
int				ft_key(int key, t_stock *stock);
int				ft_max_z(t_map *map);
int				ft_smaller_units(t_map *map);
int				ft_smaller_window(t_map *map);
int				ft_usage(void);
int				main(int ac, char **av);
t_map			*ft_parse(char *file);
t_mlx			*ft_mlx_setup(t_map *map, char *title);
void			ft_display_map(t_map *map);
void			ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_img_setup(t_mlx *mlx);
void			ft_iso(t_mlx *mlx, t_map *map);
void			ft_iso_helper(t_mlx *mlx, t_map *map, int i, int j);
void			ft_line(t_mlx *mlx, t_coord *c1, t_coord *c2);
void			ft_move(int key, t_stock *stock);
void			ft_para(t_mlx *mlx, t_map *map);
void			ft_para_helper(t_mlx *mlx, t_map *map, int i, int j);
void			ft_put_map_to_img(t_mlx *mlx, t_map *map);
void			ft_reset(t_stock *stock);
void			ft_tutorial(t_stock *stock);
void			ft_zoom_n_height(int key, t_stock *stock);
void			ft_panel_setup(t_mlx *mlx);

#endif
