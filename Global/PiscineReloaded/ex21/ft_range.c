/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:48:32 by flklein           #+#    #+#             */
/*   Updated: 2018/11/05 14:48:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc((max - min) * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		tab[i] = i + min;
		i++;
	}
	return (tab);
}
