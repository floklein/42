/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:56:46 by fklein            #+#    #+#             */
/*   Updated: 2017/10/02 15:39:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "mlx.h"

typedef	struct	s_mlx
{
	int	fractal;
	void	*ptr;
	void	*win;
	int	x_size;
	int	y_size;
	int	x_unit;
	int	y_unit;
	int	x_pos;
	int	y_pos;
	void	*img_ptr;
	char	*img_str;
}		t_mlx;

int	no_file(char *file);
int	errors(int number);
int	fractol(int fractal);
int	data_to_img(int fractal, t_mlx *mlx);

int	ft_abs(int number);

#endif
