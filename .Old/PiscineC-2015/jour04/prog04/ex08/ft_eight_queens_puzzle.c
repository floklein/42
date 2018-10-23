/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 10:56:04 by fklein            #+#    #+#             */
/*   Updated: 2015/10/21 18:24:20 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

int		queens(int n, int row, int *chess)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	if (row == n)
		count++;
	i = 0;
	while (i < n)
	{
		j = 0;
		while ((j < row && !(chess[j] == i || abs(chess[j] - i) == row - j)))
			j++;
		if (j == row)
		{
			chess[row] = i;
			count += queens(n, row + 1, chess);
		}
		i++;
	}
	return (count);
}

int		ft_eight_queens_puzzle(void)
{
	int chess[8];

	return (queens(8, 0, chess));
}

int		main(void)
{
	printf("%d", ft_eight_queens_puzzle());
}
