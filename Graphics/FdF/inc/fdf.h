/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:20:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 18:45:42 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <stdlib.h>

typedef struct	s_coord
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_coord;

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
void			ft_line(t_mlx *mlx, t_coord *coord, int color);

#endif
