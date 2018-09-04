/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:50:20 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 18:25:19 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_get_tets(t_tet *tets, t_piece **pieces)
{
	while (*pieces)
	{	
		tets->max = ft_min(*pieces);
		tets->blocs = CAT((*pieces));
		tets->pos = 0;
		tets->ident = -1;
		pieces++;
		tets++;
	}
}

void	ft_toggle(unsigned short map[16],  unsigned int blocs)
{
	unsigned int	x;
	int				i;

	i = 0;
	while (i < 4)
	{
		x = OUT(blocs, i);
		map[HGH(x)] ^= 1 << LOW(x);
		++i;
	}
}

int		ft_check(unsigned short map[16], unsigned int x)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		if (map[HGH(x & 0xff)] & (1 << LOW(x & 0xff)))
			return (-1);
		x >>= 8;
		++i;
	}
	return (0);
}

int		ft_rec(unsigned short map[16], t_tet *tets, t_tet *tet, int size)
{
	int	i;
	int	j;

	if (tet->blocs == 0)
		return (0);
	i = (tet->ident != -1) ? HGH(((tets + tet->ident)->pos) & 0xff) - 1 : -1;
	j = (tet->ident != -1) ? LOW(((tets + tet->ident)->pos) & 0xff) : -1;
	while (++i + HGH(tet->max) < size)
	{
		while (++j + LOW(tet->max) < size)
		{
			if (ft_check(map, tet->blocs + (STK((i << 4) + j))) == 0)
			{
				ft_toggle(map, tet->blocs + (tet->pos = STK((i << 4) + j)));
				if (ft_rec(map, tets, tet + 1, size) == 0)
					return (0);
				ft_toggle(map, tet->pos + tet->blocs);
			}
		}
		j = -1;
	}
	return (-1);
}

void	ft_solve(t_piece **pieces, int size, int n)
{
	t_tet			tets[n + 1];
	char			**result;
	unsigned short	map[16];

	(tets + n)->blocs = 0;
	ft_memset(map, 0, 18);
	ft_get_tets(tets, pieces);
	ft_make_idents(tets, n);
	while (ft_rec(map, tets, tets, size) == -1)
		size++;
	result = ft_create(size);
	ft_fill(result, tets, pieces);
	ft_print(result);
	ft_clear((void **)result);
	ft_clear((void **)pieces);
	free(result);
}
