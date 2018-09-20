/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 22:38:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/11 00:27:23 by flklein          ###   ########.fr       */
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
		{ //Teste le box de la case
			if (l - (l % 3) + i != l && c - (c % 3) + j != c
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
	{ //Teste toutes les lignes pour cette colonne
		if (i != l && tab[i][c] == nb)
			return (0);
		i++;
	}
	j = 0;
	while (j < 9)
	{ //Teste toutes les colonnes pour cette ligne
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
		{ //Teste si grille valide
			if (tab[i][j] != 0 && !test(tab, i, j, tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
