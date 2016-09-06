/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 13:30:12 by nthibaud          #+#    #+#             */
/*   Updated: 2015/11/05 15:09:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int len;
	int *tab;

	i = 0;
	tab = NULL;
	if (min >= max)
		return (tab);
	len = max - min;
	if (!(tab = (int*)malloc(sizeof(*tab) * len + 1)))
		return (0);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	tab[i] = '\0';
	return (tab);
}
