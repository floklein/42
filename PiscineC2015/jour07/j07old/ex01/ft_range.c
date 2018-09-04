/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:50:14 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 19:13:17 by fklein           ###   ########.fr       */
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
		tab = malloc(sizeof(int) * (max - min));
		while (min < max)
		{
			*(tab + index) = min;
			index++;
			min++;
		}
	}
	return (tab);
}
