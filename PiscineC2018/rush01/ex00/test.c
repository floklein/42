/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:38:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 21:03:39 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		test_case(int **tab, int l, int c, int nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			printf("case:%d) = %d\n", nb, tab[i][j]);
			if (i != l && j != c
					&& tab[l - (l % 3) + i][c - (c % 3) + j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		test(int **tab, int l, int c, int nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		printf("col:%d) = %d\n", nb, tab[i][c]);
		if (i != l && tab[i][c] == nb)
			return (0);
		i++;
	}
	j = 0;
	while (j < 9)
	{
		printf("line:%d) = %d\n", nb, tab[l][j]);
		if (j != c && tab[l][j] == nb)
			return (0);
		j++;
	}
	return (test_case(tab, l, c, nb));
}

int		is_valid(int **tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("=====TEST: [%d][%d] val:%d\n", i, j, tab[i][j]);
			if (tab[i][j] != 0 && !test(tab, i, j, tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
