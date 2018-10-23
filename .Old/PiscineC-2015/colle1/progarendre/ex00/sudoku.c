/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:44:28 by fklein            #+#    #+#             */
/*   Updated: 2015/10/25 18:52:59 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	display(int grid[9][9]);

int		not_on_line(int k, int grid[9][9], int i);

int		not_on_column(int k, int grid[9][9], int j);

int		not_in_block(int k, int grid[9][9], int i, int j);

int		if_valid(int grid[9][9], int position)
{
	int		i;
	int		j;
	int		k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (grid[i][j] != 0)
		return (if_valid(grid, position + 1));
	k = 1;
	while (k <= 9)
	{
		if (not_on_line(k, grid, i)
				&& not_on_column(k, grid, j) && not_in_block(k, grid, i, j))
		{
			grid[i][j] = k;
			if (if_valid(grid, position + 1))
				return (1);
		}
		k++;
	}
	grid[i][j] = 0;
	return (0);
}

void	convert(char **argv, int grid[9][9])
{
	int		index;
	int		index2;

	index = 1;
	while (index < 10)
	{
		index2 = 0;
		while (index2 < 9)
		{
			if (argv[index][index2] == '.')
				grid[index - 1][index2] = 0;
			else
			{
				grid[index - 1][index2] = argv[index][index2] - 48;
			}
			index2++;
		}
		index++;
	}
}

int		no_solution_or_print(int grid[9][9])
{
	int		index;
	int		index2;

	index = 0;
	while (index < 10)
	{
		index2 = 0;
		while (index2 < 9)
		{
			if (grid[index][index2] == 0)
			{
				write(1, "Erreur\n", 7);
				return (0);
			}
			index2++;
		}
		index++;
	}
	display(grid);
	return (0);
}

int		main(int argc, char **argv)
{
	int		grid[9][9];

	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}
	convert(argv, grid);
	if_valid(grid, 0);
	return (no_solution_or_print(grid));
}
