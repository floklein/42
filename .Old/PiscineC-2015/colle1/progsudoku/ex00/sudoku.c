/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 13:44:28 by fklein            #+#    #+#             */
/*   Updated: 2015/10/25 17:41:19 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void display (int grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(grid[i][j] + 48);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int not_on_line (int k, int grid[9][9], int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (grid[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int not_on_column (int k, int grid[9][9], int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int not_in_block (int k, int grid[9][9], int i, int j)
{
	int		i_block;
	int		j_block;
	
	i_block = i - (i % 3);
	j_block = j - (j % 3);
	i = i_block;
	while (i < i_block + 3)
	{
		j = j_block;
		while (j < j_block + 3)
		{
			if (grid[i][j] == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int if_valid (int grid[9][9], int position)
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

int		main (int argc, char **argv)
{
	int		grid[9][9];
	int		index;
	int		index2;

	if (argc != 10)
	{
		write(1, "Erreur\n", 7);
		return (0);
	}

	index = 1;
	while (index < 10)
	{
		index2 = 0;
		while (index2 < 9)
		{
			printf("%c ", argv[index][index2]);
			if (argv[index][index2] == '.')
				grid[index - 1][index2] = 0;
			else
				grid[index - 1][index2] = argv[index][index2] - 48;

			index2++;
		}
		index++;
	}

	printf("grid apres\n");
	display(grid);
	
	if_valid(grid, 0);

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
	

	printf("grid apres\n");
	display(grid);

	return (0);
}
