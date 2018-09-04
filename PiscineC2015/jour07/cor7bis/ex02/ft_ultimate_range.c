/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:18:39 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 21:16:29 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		index;
	int		*tab;

	index = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	tab = (int*)malloc(sizeof(*tab) * (max - min - 1));
	while (min < max)
	{
		*(tab + index) = min;
		index++;
		min++;
	}
	*range = tab;
	return (index);
}
