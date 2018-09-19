/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:18:39 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 19:14:52 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		index;
	int		*tab;

	index = 0;
	tab = malloc(sizeof(int) * (max - min));
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	while (min < max)
	{
		*(tab + index) = min;
		index++;
		min++;
	}
	*range = tab;
	return (index);
}