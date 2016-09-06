/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:04:03 by fklein            #+#    #+#             */
/*   Updated: 2016/07/25 16:19:45 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		ft_putchari(char c)
{
	write(1, &c, 1);
	return (1);
}

static int		ft_putstri(char *str)
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

static int		ft_putnbri(int i)
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
