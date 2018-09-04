/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:50:42 by fklein            #+#    #+#             */
/*   Updated: 2015/10/21 19:28:54 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_2_pow(int n)
{
	if (n == 0)
		return (1);
	else
		return (2 * ft_2_pow(n - 1));
}

int		ft_sqrt(int nb)
{
	int i;
	int lim;

	i = 1;
	while (ft_2_pow(2 * i) < nb && i <= 15)
		i++;
	lim = i;
	i = 1;
	while (++i <= nb / lim + 1)
	{
		if (i * i == nb)
			return (i);
	}
	return (0);
}

int		main(void)
{
	printf("%d", ft_sqrt(1600000000));
}
