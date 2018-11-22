/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:55:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/22 17:07:35 by flklein          ###   ########.fr       */
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
	char	*box;
	int		size;
}				t_map;

char		*ft_convert(char *src, char c);
int			ft_list_size(t_tetri *begin_list);
int			ft_valid_piece(char *str);
t_tetri		*ft_create_elem(char *data);
t_tetri		*ft_list_at(t_tetri *begin_list, unsigned int nbr);
t_tetri		*ft_parse(int fd);
void		ft_list_foreach(t_tetri *begin_list, void (*f)(const char *));
void		ft_list_push_back(t_tetri **begin_list, char *data);

#endif
