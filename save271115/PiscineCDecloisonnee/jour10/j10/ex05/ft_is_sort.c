/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:49:59 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 21:45:19 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		c;
	int		d;

	i = 0;
	c = 0;
	d = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			c++;
		else
			c = -2 * length;
		if (f(tab[i], tab[i + 1]) >= 0)
			d++;
		else
			d = -2 * length;
		i++;
	}
	if (c == length - 1 || d == length - 1)
		return (1);
	return (0);
}
