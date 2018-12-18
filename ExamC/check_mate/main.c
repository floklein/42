/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:37:29 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 11:29:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_piece(char p)
{
	return (p == 'P' || p == 'B' || p == 'R' || p == 'Q');
}

int		check_pawn(char **tab, int r, int c, int size)
{
	return (r - 1 >= 0
			&& ((c - 1 >= 0 && tab[r - 1][c - 1] == 'K')
				|| (c + 1 < size && tab[r - 1][c + 1] == 'K')));
}

int		check_bishop(char **tab, int row, int col, int size)
{
	int		r;
	int		c;

	r = row - 1;
	c = col - 1;
	while (r >= 0 && c >= 0 && !is_piece(tab[r][c]))
		if (tab[r--][c--] == 'K')
			return (1);
	r = row - 1;
	c = col + 1;
	while (r >= 0 && c < size && !is_piece(tab[r][c]))
		if (tab[r--][c++] == 'K')
			return (1);
	r = row + 1;
	c = col - 1;
	while (r < size && c >= 0 && !is_piece(tab[r][c]))
		if (tab[r++][c--] == 'K')
			return (1);
	r = row + 1;
	c = col + 1;
	while (r < size && c < size && !is_piece(tab[r][c]))
		if (tab[r++][c++] == 'K')
			return (1);
	return (0);
}

int		check_rook(char **tab, int row, int col, int size)
{
	int		r;
	int		c;

	r = row - 1;
	c = col;
	while (r >= 0 && !is_piece(tab[r][c]))
		if (tab[r--][c] == 'K')
			return (1);
	r = row;
	c = col + 1;
	while (c < size && !is_piece(tab[r][c]))
		if (tab[r][c++] == 'K')
			return (1);
	r = row + 1;
	c = col;
	while (r < size && !is_piece(tab[r][c]))
		if (tab[r++][c] == 'K')
			return (1);
	r = row;
	c = col - 1;
	while (c >= 0 && !is_piece(tab[r][c]))
		if (tab[r][c--] == 'K')
			return (1);
	return (0);
}

int		is_checkmate(char **tab, int size)
{
	int		r;
	int		c;

	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			if (tab[r][c] == 'P' && check_pawn(tab, r, c, size))
				return (1);
			else if (tab[r][c] == 'B' && check_bishop(tab, r, c, size))
				return (1);
			else if (tab[r][c] == 'R' && check_rook(tab, r, c, size))
				return (1);
			else if (tab[r][c] == 'Q' && (check_bishop(tab, r, c, size)
						|| check_rook(tab, r, c, size)))
				return (1);
			c++;
		}
		r++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1));
	if (is_checkmate(av + 1, ac - 1))
		return (write(1, "Success\n", 8));
	else
		return (write(1, "Fail\n", 5));
}
