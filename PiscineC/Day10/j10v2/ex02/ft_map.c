/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:43:33 by flklein           #+#    #+#             */
/*   Updated: 2018/09/12 15:14:47 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*cpy;
	int		i;

	if (!(cpy = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		cpy[i] = (*f)(tab[i]);
		i++;
	}
	return (cpy);
}
