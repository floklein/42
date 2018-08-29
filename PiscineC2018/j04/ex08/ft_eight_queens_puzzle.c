/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:21:57 by flklein           #+#    #+#             */
/*   Updated: 2018/08/29 17:53:48 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		test_line(int *tab, int j)
{
	int		c;

	c = 0;
	while (c <= 7 && tab[c] == -1)
	{
		if (tab[c] == j)
			return (0);
		c++;
	}
	return (1);
}

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

int		test_diag(int *tab, int i, int j)
{
	int		c;

	c = 0;
	while (c <= 7 && tab[c] != -1)
	{
		if (ft_abs(c - i) == ft_abs(tab[c] - j))
			return (0);
		c++;
	}
	return (1);
}

int		add_queen(int *tab, int i, int j)
{

}
