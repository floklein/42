/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 10:56:04 by fklein            #+#    #+#             */
/*   Updated: 2015/10/24 15:04:32 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}

int		abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

void	queens(int n, int row, char *chess)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	if (row == n)
	{
		count++;
		ft_putstr(chess);
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while ((j < row && !(chess[j] == i + 48
						|| abs(chess[j] + 48 - i) == row - j)))
			j++;
		if (j == row)
		{
			chess[row] = i + 48;
				if (j == n - 1)
					ft_putstr(chess);
		}
		i++;
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	char chess[8];

	queens(8, 0, chess);
}

int		main(void)
{
	ft_eight_queens_puzzle_2();
}
