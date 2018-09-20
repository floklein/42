/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:38:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 02:36:02 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		test_c_l(char **tab, int pos, char nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		if (tab[i][pos % 9] == nb)
			return (0);
		i++;
	}
	j = 0;
	while (j < 9)
	{
		if (tab[pos / 9][j] == nb)
			return (0);
		j++;
	}
	return (1);
}

int		test_case(char **tab, int pos, char nb)
{
	int		l;
	int		c;
	int		i;
	int		j;

	l = pos / 9;
	c = pos % 9;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[l - (l % 3) + i]
					[c - (c % 3) + j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		test(char **tab, int pos, char nb)
{
	return (test_c_l(tab, pos, nb) && test_case(tab, pos, nb));
}
