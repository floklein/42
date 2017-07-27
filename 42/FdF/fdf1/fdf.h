/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:56:46 by fklein            #+#    #+#             */
/*   Updated: 2017/07/27 16:42:10 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <mlx.h>

typedef struct	s_data
{
	int	**tab;
	int	width;
	int	height;
	int	max;
	int	min;
}		t_data;

typedef	struct	s_mlx
{
	t_data	data;
	void	*ptr;
	void	*win;
	int	x_size;
	int	y_size;
	int	x_unit;
	int	y_unit;
	int	z_unit;
	void	*img_ptr;
	char	*img_str;
}		t_mlx;

int	check_file(int *fd, char *file, t_data *data);
int	no_file(char *file);
int	errors(int number);
int	fdf(t_data *data);
int	display(t_data *data, t_mlx *mlx);

void	ft_putstr_fd(char *str, int fd);
int	get_next_line(int fd, char **line);
char	**ft_strsplit(char const *line, char c);
int	ft_atoi(char const *str);
int	ft_abs(int number);

#endif
