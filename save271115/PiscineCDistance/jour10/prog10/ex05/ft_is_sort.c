/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:49:59 by fklein            #+#    #+#             */
/*   Updated: 2015/11/26 18:52:47 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			c++;
		else
			c = -2 * length;
		i++;
	}
	if (length == 0 || length == 1 || c == length - 1)
		return (1);
	return (0);
}

#include <stdio.h>

int		ft_croissant(int a, int b)
{
	return (a - b);
}

int		main(void)
{
	 int	tab[2];

	 tab[0] = -147116;
	 tab[1] = -81676;
	 printf("%d", ft_is_sort(tab, 2, &ft_croissant));
}
