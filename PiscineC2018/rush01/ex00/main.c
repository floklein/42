/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:17:17 by flklein           #+#    #+#             */
/*   Updated: 2018/09/11 00:25:23 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		this_is_the_end(int **tab, int **tab_cpy, int *res)
{
	if (*res == 0) //1er resulat -> on fait une copie du tableau
		copy_tab(tab_cpy, tab);
	(*res)++;
	if (*res == 2) //2eme -> c'est trop = erreur
		return (1);
	return (0);
}

int		solve_sudoku(int **tab, int **tab_cpy, int *res, int pos)
{
	int		l;
	int		c;
	int		nb;

	if (pos == 81) //Condition de fin : derniere position de la grille
		return (this_is_the_end(tab, tab_cpy, res));
	l = pos / 9; //Ligne
	c = pos % 9; //Colonne
	if (tab[l][c] != 0) //Si un chiffre deja ecrit -> case suivante
		return (solve_sudoku(tab, tab_cpy, res, pos + 1));
	nb = 1;
	while (nb <= 9) //Test tous les nbs possibles
	{
		if (test(tab, l, c, nb)) //Nb respecte conditions ?
		{
			tab[l][c] = nb; //Oui -> on l'ecrit
			if (solve_sudoku(tab, tab_cpy, res, pos + 1)) //Case suivante
				return (1);
		}
		nb++; //Non -> nombre suivant
	}
	tab[l][c] = 0; //Aucun nb fonctionne -> on remet a 0 la case
	return (0);
}

int		main(int ac, char **av)
{
	int		**tab;
	int		**tab_cpy;
	int		res;

	if (ac != 10 || !(tab = create_tab(av)) //Verifie le nombre de lignes
			|| !(tab_cpy = create_tab(av)) || !(is_valid(tab))) //Sudoku valide ?
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solve_sudoku(tab, tab_cpy, &res, 0); //Appel du solver
	if (res == 1)
		print_tab(tab_cpy); //Affiche le resultat unique
	else
		write(1, "Error\n", 6);
	return (0);
}
