/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:18:23 by flklein           #+#    #+#             */
/*   Updated: 2018/12/15 20:46:42 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdbl(double n, int p)
{
	int		i;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putnbr((int)n);
	ft_putchar('.');
	n -= (int)n;
	i = 0;
	while (i < p)
	{
		ft_putnbr(ft_abs((int)(n *= 10)));
		n -= (int)n;
		i++;
	}
}
