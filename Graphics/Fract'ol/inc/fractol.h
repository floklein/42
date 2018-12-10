/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:55:45 by flklein           #+#    #+#             */
/*   Updated: 2018/12/10 18:49:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_coord
{
	int		x;
	int		y;
	int		color;
}				t_coord;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	void	*img;
	int		*str;
	double	zoom;
	double	move_x;
	double	move_y;
	int		iter;
	int		fractal;
	int		panel_choice;
	int		panel[5][5];
	t_coord	*c1;
	t_coord	*c2;
}				t_mlx;

typedef struct	s_stock
{
	t_mlx	*mlx;
}				t_stock;

char			*ft_title(char *title);
double			ft_cmod(t_complex a);
int				ft_close(void);
int				ft_hsv_to_rgb(double h, double s, double v);
int				ft_key(int key, t_stock *stock);
int				ft_parse(char *file);
int				ft_usage(void);
t_complex		ft_cadd(t_complex a, t_complex b);
t_complex		ft_csqr(t_complex a);
t_mlx			*ft_mlx_setup(char *title);
void			ft_fill_pixel(t_mlx *mlx, int x, int y, int color);
void			ft_julia(t_mlx *mlx);
void			ft_mandelbrot(t_mlx *mlx);
void			ft_move(int key, t_stock *stock);
void			ft_put_fractal_to_img(t_mlx *mlx);
void			ft_reset(t_stock *stock);
void			ft_tutorial(t_stock *stock);
void			ft_zoom_n_iter(int key, t_stock *stock);

#endif
