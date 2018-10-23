/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:49:38 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 23:43:54 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*t_tab;

	i = 0;
	if ((t_tab = malloc(sizeof(*t_tab) * length)) == NULL)
		return (NULL);
	while (i < length)
	{
		t_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (t_tab);
}
