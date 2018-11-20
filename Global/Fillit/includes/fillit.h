/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:55:46 by flklein           #+#    #+#             */
/*   Updated: 2018/11/20 19:16:53 by flklein          ###   ########.fr       */
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
	struct s_tetri	*next;
}				t_tetri;

int		ft_list_size(t_tetri *begin_list);
int		main(int ac, char **av);
t_tetri		*ft_create_elem(char *data);
t_tetri		*ft_list_at(t_tetri *begin_list, unsigned int nbr);
t_tetri		*ft_parse(int fd);
void		ft_list_push_back(t_tetri **begin_list, char *data);
void		ft_list_foreach(t_tetri *begin_list, void (*f)(const char *));

#endif
