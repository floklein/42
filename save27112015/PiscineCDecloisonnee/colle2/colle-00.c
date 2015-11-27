/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:44:20 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 17:24:22 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle0x.h"

char	test0(int l, int h, int x, int y)
{
	if (l == 1 && h == 1)
		return ('o');
	else if (l == x && h == 1)
		return ('o');
	else if (l == 1 && h == y)
		return ('o');
	else if (l == x && h == y)
		return ('o');
	else if (h == 1 || h == y)
		return ('-');
	else if (l == 1 || l == x)
		return ('|');
	else
		return (' ');
}

char	*colle0(int x, int y)
{
	int		lc;
	int		hc;
	char	*tab;
	int		index;

	lc = 1;
	hc = 1;
	index = 0;
	if ((tab = (char*)malloc(sizeof(*tab) * ((x + 1) * y + 1))) == NULL)
		return (NULL);
	while (hc <= y)
	{
		while (lc <= x)
		{
			tab[index] = test0(lc, hc, x, y);
			lc++;
			index++;
		}
		tab[index] = '\n';
		lc = 1;
		hc++;
		index++;
	}
	tab[index] = '\0';
	return (tab);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_putstr(colle0(atoi(av[1]), atoi(av[2])));
	return (0 * ac);
}
