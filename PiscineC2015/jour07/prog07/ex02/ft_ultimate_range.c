/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:18:39 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 16:48:59 by fklein           ###   ########.fr       */
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
	while (index < max - 1)
	{
		*(tab + index) = min + index;
		index++;
	}
	*range = tab;
	return (index);
}
