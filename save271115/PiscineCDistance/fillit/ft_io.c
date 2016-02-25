/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:01:33 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 07:41:45 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_out(char *s)
{
	ft_putstr(s);
	exit(0);
}

void	ft_clear(void **tab)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i] != NULL)
			ft_memdel(tab + i);
		ft_memdel(tab);
	}
}

void	ft_print(char **tab)
{
	int		i;

	i = -1;
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

char	**ft_create(int size)
{
	char	**tab;
	int		i;

	if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if ((tab[i] = malloc(size + 1)) == NULL)
			return (NULL);
		ft_memset(tab[i], '.', size);
		tab[i][size] = '\0';
	}
	tab[size] = NULL;
	return (tab);
}

void	ft_fill(char **tab, t_tet *tet, t_piece **pieces)
{
	int		x;
	int		y;
	t_piece	*p;
	char	id;

	id = 'A';
	while (*pieces)
	{
		p = *pieces;
		x = HGH(tet->pos);
		y = LOW(tet->pos);
		tab[x + HGH(p->_0)][y + LOW(p->_0)] = id;
		tab[x + HGH(p->_1)][y + LOW(p->_1)] = id;
		tab[x + HGH(p->_2)][y + LOW(p->_2)] = id;
		tab[x + HGH(p->_3)][y + LOW(p->_3)] = id;
		pieces++;
		tet++;
		id++;
	}
}
