/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 12:12:09 by fklein            #+#    #+#             */
/*   Updated: 2015/10/24 18:03:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_factorial(int nb)
{
	int i;
	int val;

	i = 0;
	val = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb-- > 1)
		val = val * nb;
	return (val);
}

int		main(void)
{
	printf("%d", ft_iterative_factorial(13));
}
