/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 22:12:51 by flklein          ###   ########.fr       */
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
	int		x;
	int		y;
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
	int		*data;
}				t_mlx;

int				ft_key(int key, void *mlx);
t_mlx			*ft_mlx_setup(int width, int height);
void			ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_img_setup(t_mlx *mlx);
void			ft_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2);
t_map			*ft_parse(char *file);
void			ft_display_map(t_map *map);

#endif
