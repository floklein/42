/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:49:59 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 00:55:04 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_decreasing(int *tab, int length, int (*f)(int, int), int i)
{
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_increasing(int *tab, int length, int (*f)(int, int), int i)
{
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	if (tab == NULL)
		return (0);
	if (length == 1 || length == 0)
		return (1);
	i = 0;
	while ((*f)(tab[i], tab[i + 1]) == 0 && i < length - 1)
		i++;
	if ((*f)(tab[i], tab[i + 1]) < 0 && i < length - 1)
		return (ft_is_increasing(tab, length, f, i));
	if ((*f)(tab[i], tab[i + 1]) > 0 && i < length - 1)
		return (ft_is_decreasing(tab, length, f, i));
	return (1);
}
