/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 10:16:36 by thifranc          #+#    #+#             */
/*   Updated: 2015/10/25 21:42:18 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_sudoku(char **tab, int x, int y);

int		ft_size_test(char **tab);

int		ft_char_test(char **tab);

void	ft_write(char **tab)
{
	int ct;
	int ct2;

	ct = 1;
	while (ct <= 9)
	{
		ct2 = 0;
		while (ct2 <= 8)
		{
			write(1, &tab[ct][ct2], 1);
			write(1, " ", 1);
			ct2++;
		}
		write(1, "\n", 1);
		ct++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	if (ft_size_test(argv) == 0)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	if (ft_char_test(argv) == 0)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	else if (ft_sudoku(argv, 0, 1) == 0)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	else
		ft_write(argv);
}
