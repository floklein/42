/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:52:34 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 22:52:36 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_protos.h"

void	ft_add(int a, int b)
{
	long	tmp;

	tmp = a + b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_sub(int a, int b)
{
	long	tmp;

	tmp = a - b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_mul(int a, int b)
{
	long	tmp;

	tmp = a * b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_div(int a, int b)
{
	long	tmp;

	tmp = a / b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}

void	ft_mod(int a, int b)
{
	long	tmp;

	tmp = a % b;
	ft_putnbr(tmp);
	ft_putchar('\n');
}
