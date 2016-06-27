/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:03:57 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 18:21:43 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structs.h"
# include "libft/libft.h"
# define USE		"usage: fillit source_file\n"
# define ERR		"error\n"
# define BLOC		'#'
# define EMPT		'.'
# define LINE		'\n'
# define TET_SIZE	4
# define HGH(x)		(((x) & 0xf0) >> 4)
# define LOW(x)		((x) & 0x0f)
# define CAT(x)		((x->_0) << 24) + ((x->_1) << 16) + ((x->_2) << 8) + x->_3
# define STK(x)		((x) << 24) + ((x) << 16) + ((x) << 8) + (x)
# define OUT(x, o)	(x & ((0xFF) << (o << 3))) >> (o << 3)

void			ft_out(char *s);
void			ft_clear(void **tab);
unsigned char	ft_min(t_piece *piece);
void			ft_solve(t_piece **pieces, int size, int n);
int				ft_root(int nbr);
char			**ft_create(int size);
void			ft_fill(char **tab, t_tet *tet, t_piece **pieces);
void			ft_print(char **tab);
void			ft_make_idents(t_tet *tets, int n);

#endif
