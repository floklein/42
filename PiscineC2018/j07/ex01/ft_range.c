/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:01:50 by flklein           #+#    #+#             */
/*   Updated: 2018/09/04 18:41:49 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		i;

	if (!(tab = (int*)malloc((max - min) * sizeof(int))))
		return (NULL);
	i = min;
	while (i < max)
	{
		
	}
}
