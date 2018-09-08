/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:17:17 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 01:19:21 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		solve_sudoku(int **tab, int pos)
{
	int		nb;

	if (pos == 81)
	{
		return (1);
	}
	if (tab[pos / 9][pos % 9] != 0)
		return (solve_sudoku(tab, pos + 1));
	nb = 1;
	while (nb <= 9)
	{
		if (test(tab, pos, nb))
		{
			tab[pos / 9][pos % 9] = nb;
			if (solve_sudoku(tab, pos + 1))
				return (1);
			tab[pos / 9][pos % 9] = 0;
		}
		nb++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		**tab;

	if (ac != 10 || !(tab = create_tab(av)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_tab(tab);
	ft_putchar('\n');
	solve_sudoku(tab, 0);
	print_tab(tab);
	return (0);
}
