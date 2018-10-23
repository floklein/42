/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 20:19:39 by flklein           #+#    #+#             */
/*   Updated: 2018/09/11 00:29:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		**create_tab(char **av)
{ //Cree le tableau de tableaux d'entiers a partir des arguments
	int		**tab;
	int		i;
	int		j;

	if (!(tab = (int **)malloc(sizeof(int *) * 9)))
		return (NULL);
	i = -1;
	while (i++ < 8)
	{
		if (ft_strlen(av[i + 1]) != 9
				|| !(tab[i] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		j = -1;
		while (j++ < 8)
		{
			if (av[i + 1][j] == '.') //Si . -> 0
				tab[i][j] = 0;
			else if (av[i + 1][j] >= '1' && av[i + 1][j] <= '9') //Si nb -> ok
				tab[i][j] = av[i + 1][j] - '0';
			else //Sinon (alpha, symbole, etc) -> erreur
				return (NULL);
		}
	}
	return (tab);
}

void	copy_tab(int **tab, int **old)
{ //Simple copie d'un tableau dans un nouveau
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			tab[i][j] = old[i][j];
			j++;
		}
		i++;
	}
}

void	print_tab(int **tab)
{ //Affichage du tableau final
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(tab[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
