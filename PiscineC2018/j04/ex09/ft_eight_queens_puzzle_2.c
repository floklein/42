/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:14:34 by flklein           #+#    #+#             */
/*   Updated: 2018/08/30 02:44:07 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		test(int *tab, int i, int j)
{
	int		c;

	c = 0;
	while (c <= 7 && tab[c] != -1)
	{
		if (tab[c] == j)
			return (0);
		c++;
	}
	c = 0;
	while (c <= 7 && tab[c] != -1)
	{
		if ((c - i < 0 ? i - c : c - i)
				== (tab[c] - j < 0 ? j - tab[c] : tab[c] - j))
			return (0);
		c++;
	}
	return (1);
}

void	display(int *tab)
{
	int		c;

	c = 0;
	while (c <= 7)
		ft_putchar(tab[c++] + 48);
	ft_putchar('\n');
}

int		add_queen(int *tab, int *res, int i, int j)
{
	int		c;
	int		tab_cpy[8];

	if (i == 8)
	{
		*res = *res + 1;
		display(tab);
		return (0);
	}
	j = 0;
	while (j++ <= 7)
	{
		if (test(tab, i, j))
		{
			c = -1;
			while (tab[c++] != -1 && c <= 7)
				tab_cpy[c] = tab[c];
			tab_cpy[i] = j;
			if (add_queen(tab_cpy, res, i + 1, 0))
				return (1);
		}
	}
	return (0);
}

int		ft_eight_queens_puzzle_2(void)
{
	int		tab[8];
	int		ind;
	int		res;
	int		*p_res;

	res = 0;
	p_res = &res;
	ind = -1;
	while (ind++ <= 7)
		tab[ind] = -1;
	add_queen(tab, p_res, 0, 0);
	return (res);
}

int		main()
{
	ft_eight_queens_puzzle_2();
}
