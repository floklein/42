/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:57:15 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/07 17:32:21 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putchari(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstri(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != 0)
	{
		ft_putchari(str[i]);
		i++;
	}
	return (i);
}

int		ft_putnbri(int i)
{
	int		nb;
	long	m;

	nb = 0;
	m = 1;
	if (i == 0)
		return (ft_putchari('0'));
	if (i == -2147483648)
		return (ft_putstri("-2147483648"));
	if (i < 0)
	{
		nb += ft_putchari('-');
		i = -i;
	}
	while (i != 0)
	{
		m = (m * 10) + (i % 10);
		i /= 10;
	}
	while (m != 1)
	{
		nb += ft_putchari((m % 10) + 48);
		m /= 10;
	}
	return (nb);
}
