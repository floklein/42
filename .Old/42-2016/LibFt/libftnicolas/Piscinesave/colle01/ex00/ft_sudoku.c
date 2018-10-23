/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 09:28:27 by thifranc          #+#    #+#             */
/*   Updated: 2015/10/25 22:15:41 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_line_test(char c, char *str);

int	ft_col_test(char c, char **tab, int x);

int ft_bloc_test(char c, char **tab, int x, int y);

int	ft_sudoku(char **tab, int x, int y);

int	ft_global_test(char **tab, int x, int y, char c)
{
	if (ft_line_test(c, tab[y]) == 0
		&& ft_col_test(c, tab, x) == 0
		&& ft_bloc_test(c, tab, x, y) == 0)
	{
		tab[y][x] = c;
		if (x == 8)
		{
			if (ft_sudoku(tab, 0, y + 1) == 1)
				return (1);
		}
		else if (ft_sudoku(tab, x + 1, y) == 1)
			return (1);
	}
	return (0);
}

int	ft_last_case(char **tab, int x, int y)
{
	char c;

	c = '1';
	if (x == 8 && y == 9)
		while (c <= '9')
		{
			if (ft_line_test(c, tab[y]) == 0
				&& ft_col_test(c, tab, x) == 0
				&& ft_bloc_test(c, tab, x, y) == 0)
			{
				tab[y][x] = c;
				return (1);
			}
			c++;
		}
	return (0);
}

int	ft_nb_test(char **tab, int *x, int *y)
{
	if (*x == 8)
	{
		*x = 0;
		(*y)++;
	}
	else
		(*x)++;
	return (ft_sudoku(tab, *x, *y));
}

int	ft_sudoku(char **tab, int x, int y)
{
	char c;

	c = '1';
	if (x == 8 && y == 9)
		return (ft_last_case(tab, 8, 9));
	if (tab[y][x] != '.')
		return (ft_nb_test(tab, &x, &y));
	while (c <= '9')
	{
		if (ft_global_test(tab, x, y, c) == 1)
			return (1);
		c++;
	}
	tab[y][x] = '.';
	return (0);
}
