/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:53:58 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/07 17:32:32 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbrui(unsigned int i)
{
	int		nb;
	long	m;

	nb = 0;
	m = 1;
	if (i == 0)
		return (ft_putchari('0'));
	while (i != 0)
	{
		m *= 10;
		m += i % 10;
		i /= 10;
	}
	while (m != 1)
	{
		nb += ft_putchari((m % 10) + 48);
		m /= 10;
	}
	return (nb);
}

int		ft_putnbroi(unsigned int i)
{
	int		nb;
	long	m;

	nb = 0;
	m = 1;
	if (i == 0)
		return (ft_putchari('0'));
	while (i != 0)
	{
		m *= 8;
		m += i % 8;
		i /= 8;
	}
	while (m != 1)
	{
		nb += ft_putchari((m % 8) + 48);
		m /= 8;
	}
	return (nb);
}

int		ft_putnbrxi(unsigned int i)
{
	int		nb;
	long	m;

	nb = 0;
	m = 1;
	if (i == 0)
		return (ft_putchari('0'));
	while (i != 0)
	{
		m *= 16;
		m += i % 16;
		i /= 16;
	}
	while (m != 1)
	{
		if (m % 16 >= 10)
			nb += ft_putchari((m % 16) + 87);
		else
			nb += ft_putchari((m % 16) + 48);
		m /= 16;
	}
	return (nb);
}

int		ft_putnbrmxi(unsigned int i)
{
	int		nb;
	long	m;

	nb = 0;
	m = 1;
	if (i == 0)
		return (ft_putchari('0'));
	while (i != 0)
	{
		m *= 16;
		m += i % 16;
		i /= 16;
	}
	while (m != 1)
	{
		if (m % 16 >= 10)
			nb += ft_putchari((m % 16) + 55);
		else
			nb += ft_putchari((m % 16) + 48);
		m /= 16;
	}
	return (nb);
}

int		ft_putpti(long unsigned int i)
{
	int				nb;
	unsigned long	m;

	nb = 0;
	m = 1;
	nb += ft_putstri("0x");
	if (i == 0)
		return (nb + ft_putchari('0'));
	while (i != 0)
	{
		m *= 16;
		m += i % 16;
		i /= 16;
	}
	while (m > 1)
	{
		if (m % 16 >= 10)
			nb += ft_putchari((m % 16) + 87);
		else
			nb += ft_putchari((m % 16) + 48);
		m /= 16;
	}
	return (nb);
}
