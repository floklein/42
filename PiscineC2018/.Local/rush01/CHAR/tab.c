/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 20:19:39 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 02:34:36 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

char	**create_tab(char **av)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char **)malloc(sizeof(char *) * 9)))
		return (NULL);
	i = 0;
	while (i < 9)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * 9)))
			return (NULL);
		j = 0;
		while (j < 9)
		{
			if (av[i + 1][j] == '.')
				tab[i][j] = 0;
			else if (av[i + 1][j] >= '1' && av[i + 1][j] <= '9')
				tab[i][j] = av[i + 1][j] - '0';
			else
				return (NULL);
			j++;
		}
		i++;
	}
	return (tab);
}

int		**copy_tab(int **old)
{
	int		**tab;
	int		i;
	int		j;

	if (!(tab = (int **)malloc(sizeof(int *) * 9)))
		return (NULL);
	i = 0;
	while (i < 9)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * 9)))
			return (NULL);
		j = 0;
		while (j < 9)
		{
			tab[i][j] = old[i][j];
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_tab(char **tab)
{
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
