/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:17:17 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 02:36:20 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		solve_sudoku(char **tab, int pos)
{
	int		l;
	int		c;
	char	nb;

	if (pos == 81)
		return (1);
	l = pos / 9;
	c = pos % 9;
	if (tab[l][c] != 0)
		return (solve_sudoku(tab, pos + 1));
	nb = 1;
	while (nb <= 9)
	{
		if (test(tab, pos, nb))
		{
			tab[l][c] = nb;
			if (solve_sudoku(tab, pos + 1))
				return (1);
			tab[l][c] = 0;
		}
		nb++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	**tab;

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
