/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:21:57 by flklein           #+#    #+#             */
/*   Updated: 2018/08/29 23:00:56 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		test_line(int *tab, int j)
{
	int		c;

	c = 0;
	while (c <= 7 && tab[c] != -1)
	{
		if (tab[c] == j)
			return (0);
		c++;
	}
	return (1);
}

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

int		test_diag(int *tab, int i, int j)
{
	int		c;

	c = 0;
	while (c <= 7 && tab[c] != -1)
	{
		if (ft_abs(c - i) == ft_abs(tab[c] - j))
			return (0);
		c++;
	}
	return (1);
}

int		add_queen(int *tab, int *res, int i, int j)
{
	int		c;
	int		tab_cpy[8];

	if (i == 8)
	{
		*res = *res + 1;
		printf("==== %d%d%d%d%d%d%d%d\n",
				tab[0],tab[1],tab[2],tab[3],tab[4],tab[5],tab[6],tab[7]);
		return (0);
	}
	j = 0;
	while (j <= 7)
	{
//		printf("%d>%d\n", i, j);
		if (test_line(tab, j) && test_diag(tab, i, j))
		{
			c = 0;
			while (tab[c] != -1 && c <= 7)
			{
				tab_cpy[c] = tab[c];
				c++;
			}
			tab_cpy[i] = j;
			if (add_queen(tab_cpy, res, i + 1, 0))
				return (1);
		}
		j++;
	}
	return (0);
}

int		ft_eight_queens_puzzle(void)
{
	int		tab[8];
	int		ind;
	int		*res;
	int		i;

	*res = 0;
	ind = -1;
	while (ind++ <= 7)
		tab[ind] = -1;
	add_queen(tab, res, 0, 0);
	return (*res);
}

int		main()
{
	printf("TADA : %d\n", ft_eight_queens_puzzle());
}
