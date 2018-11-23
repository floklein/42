/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:55:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/23 19:28:38 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_tetri
{
	char			*piece;
	int				placed;
	struct s_tetri	*next;
}				t_tetri;

typedef struct	s_map
{
	char			*box;
	int				size;
	int				area;
}				t_map;

int				ft_backtracking(t_tetri *tetri, t_map *map, int pos);
int				ft_convert(char **src, char c);
int				ft_list_size(t_tetri *begin_list);
int				ft_resting_pieces(t_tetri *tetri);
int				ft_test(t_tetri *cur, t_map *map, int pos);
int				ft_valid_piece(char *str);
int				main(int ac, char **av);
t_map			*ft_solve(t_tetri *tetri);
t_tetri			*ft_create_elem(char *data);
t_tetri			*ft_list_at(t_tetri *begin_list, unsigned int nbr);
t_tetri			*ft_parse(int fd);
void			ft_fill_map(t_tetri *cur, t_map *map, int pos, int mode);
void			ft_list_push_back(t_tetri **begin_list, char *data);

#endif
