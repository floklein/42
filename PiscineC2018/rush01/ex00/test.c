/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:38:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/08 22:44:47 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		test_c_l(int **tab, int pos, int nb)
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

int		test_case(int **tab, int pos, int nb)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[(pos / 9) - ((pos / 9) % 3) + i]
					[(pos % 9) - ((pos % 9) % 3) + j] == nb)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		test(int **tab, int pos, int nb)
{
	return (test_c_l(tab, pos, nb) && test_case(tab, pos, nb));
}
