/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 00:35:28 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 02:42:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display(char *colle, int x, int y)
{
	ft_putstr(colle);
	ft_putstr(" [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putchar(']');
}

int		success1(int what_else, int x, int y)
{
	if (what_else > 0)
		ft_putstr(" || ");
	display("[colle-01]", x, y);
	return (1);
}

int		success2(int what_else, int x, int y)
{
	if (what_else > 0)
		ft_putstr(" || ");
	display("[colle-02]", x, y);
	return (1);
}

int		success3(int what_else, int x, int y)
{
	if (what_else > 0)
		ft_putstr(" || ");
	display("[colle-03]", x, y);
	return (1);
}

int		success4(int what_else, int x, int y)
{
	if (what_else > 0)
		ft_putstr(" || ");
	display("[colle-04]", x, y);
	return (1);
}
