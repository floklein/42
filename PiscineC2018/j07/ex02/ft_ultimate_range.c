/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:59:40 by flklein           #+#    #+#             */
/*   Updated: 2018/09/04 23:12:03 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		*tab;
	int		i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if (!(*range = (int*)malloc((max - min) * sizeof(int))))
	{
		range = NULL;
		return (0);
	}
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (max - min);
}
