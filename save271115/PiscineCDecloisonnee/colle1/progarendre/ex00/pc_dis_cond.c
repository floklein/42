/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_dis_cond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:13:49 by fklein            #+#    #+#             */
/*   Updated: 2015/10/25 18:52:57 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int grid[9][9])
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

int		not_on_line(int k, int grid[9][9], int i)
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

int		not_on_column(int k, int grid[9][9], int j)
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

int		not_in_block(int k, int grid[9][9], int i, int j)
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
