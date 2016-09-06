/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 17:40:59 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 16:09:42 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	int				**pos;
	int				sq_x;
	int				sq_y;
	char			c;
}					t_tetri;

typedef struct		s_square
{
	int				x_max;
	int				y_max;
}					t_square;

int					check_file(char *file, int *tetri_nb);
t_tetri				*stock_tetri(char *file, int tetri_nb);
void				get_block_pos(char *buf, t_tetri *tetri,
	int nb, int *pos_ref);
int					is_outside(t_tetri tetri, t_square *sq);
int					is_overlapping(t_tetri *tetri, int i);
void				solver(t_tetri *tetri, t_square **square, int tetri_nb);
void				print_result(t_tetri *tetri, int tetri_nb, t_square sq);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putchar_stderr(char c);
void				ft_putstr_stderr(const char *str);
void				ft_putendl(const char *str);
int					ft_sqrt(int nb);
#endif
