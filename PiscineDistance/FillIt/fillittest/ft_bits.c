/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:40:34 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 17:21:53 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <math.h>

unsigned char	ft_max(t_piece *piece)
{
	unsigned char	max;

	max = piece->_0;
	max = ((((max & 0xF0) < (piece->_1 & 0xF0)) ? piece->_1 : max)
			& 0xF0) + (max & 0x0F);
	max = ((((max & 0xF0) < (piece->_2 & 0xF0)) ? piece->_2 : max)
			& 0xF0) + (max & 0x0F);
	max = ((((max & 0xF0) < (piece->_3 & 0xF0)) ? piece->_3 : max)
			& 0xF0) + (max & 0x0F);
	max = ((((max & 0x0F) < (piece->_1 & 0x0F)) ? piece->_1 : max)
			& 0x0F) + (max & 0xF0);
	max = ((((max & 0x0F) < (piece->_2 & 0x0F)) ? piece->_2 : max)
			& 0x0F) + (max & 0xF0);
	max = ((((max & 0x0F) < (piece->_3 & 0x0F)) ? piece->_3 : max)
			& 0x0F) + (max & 0xF0);
	return (max);
}

unsigned char	ft_min(t_piece *piece)
{
	unsigned char	orig;

	orig = piece->_0;
	orig = ((((orig & 0xF0) > (piece->_1 & 0xF0)) ? piece->_1 : orig)
			& 0xF0) + (orig & 0x0F);
	orig = ((((orig & 0xF0) > (piece->_2 & 0xF0)) ? piece->_2 : orig)
			& 0xF0) + (orig & 0x0F);
	orig = ((((orig & 0xF0) > (piece->_3 & 0xF0)) ? piece->_3 : orig)
			& 0xF0) + (orig & 0x0F);
	orig = ((((orig & 0x0F) > (piece->_1 & 0x0F)) ? piece->_1 : orig)
			& 0x0F) + (orig & 0xF0);
	orig = ((((orig & 0x0F) > (piece->_2 & 0x0F)) ? piece->_2 : orig)
			& 0x0F) + (orig & 0xF0);
	orig = ((((orig & 0x0F) > (piece->_3 & 0x0F)) ? piece->_3 : orig)
			& 0x0F) + (orig & 0xF0);
	piece->_0 -= orig;
	piece->_1 -= orig;
	piece->_2 -= orig;
	piece->_3 -= orig;
	return (ft_max(piece));
}

int				ft_root(int n)
{
	int		k;

	k = 0;
	while (k * k < n)
		k++;
	return (k);
}

void	ft_make_idents(t_tet *tets, int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < i)
			if ((tets + i)->blocs == (tets + j)->blocs)
				(tets + i)->ident = j;
	}
}
