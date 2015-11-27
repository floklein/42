/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 12:11:05 by fklein            #+#    #+#             */
/*   Updated: 2015/10/20 13:58:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb != 0)
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

int		main(void)
{
	int a;

	a = 6502; 
	ft_putnbr(a);
	return (0);
}
