/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:05:29 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 18:20:12 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef union	u_pos
{
	unsigned int	blocs;
	unsigned char	lones[4];
}				t_pos;

typedef struct  s_piece
{
    unsigned char	_0;
    unsigned char	_1;
    unsigned char	_2;
    unsigned char	_3;
}               t_piece;

typedef struct	s_tet
{
	unsigned int	blocs;
	unsigned int	pos;
	int				ident;
	unsigned char	max;
}				t_tet;

#endif
