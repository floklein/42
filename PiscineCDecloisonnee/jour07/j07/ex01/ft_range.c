/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:50:14 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 21:03:31 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		index;

	index = 0;
	if (min >= max)
		return (tab = NULL);
	else
	{
		tab = (int*)malloc(sizeof(*tab) * (max - min - 1));
		while (min < max)
		{
			*(tab + index) = min;
			index++;
			min++;
		}
	}
	return (tab);
}
