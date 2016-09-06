/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 18:31:15 by nthibaud          #+#    #+#             */
/*   Updated: 2015/11/06 22:02:30 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb <= -10)
		{
			ft_putchar('-');
			ft_putnbr(-1 * (nb / 10));
			ft_putchar('0' + -1 * (nb % 10));
		}
		if (nb > -10)
		{
			ft_putchar('-');
			ft_putchar('0' - nb);
		}
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar('0' + nb % 10);
		}
		else
			ft_putchar('0' + nb);
	}
}

int		main(void)
{
	int n;

	n = -1245;
	ft_putnbr(n);
	return (0);
}
