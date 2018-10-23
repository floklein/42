/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:17:23 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/10 18:17:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;
	int *tab;

	i = 0;
	len = max - min;\
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if ((tab = (int*)malloc(sizeof(*tab) * len)) == NULL)
		return (0);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (i);
}
