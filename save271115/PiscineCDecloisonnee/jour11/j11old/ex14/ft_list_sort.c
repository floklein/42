/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:53:12 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 23:08:20 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	swap(void *a, void *b)
{
	void *c;

	c = a;
	a = b;
	b = c;
}

int		ft_list_size(t_list *begin_list)
{
	if (begin_list->next == NULL)
		return (1);
	else
		return (1 + ft_list_size(begin_list->next));
}

t_list	*l_at(t_list *begin_list, unsigned int nbr)
{
	if (nbr == 1 && begin_list->next == NULL)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	else
		return (l_at(begin_list->next, nbr - 1));
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i1;
	int		i2;
	int		size;

	i1 = 0;
	i2 = 0;
	size = ft_list_size(*begin_list);
	while (i1 < size)
	{
		while (i2 < size - i1)
			if (cmp(l_at(*begin_list, i2), l_at(*begin_list, i2 + 1)))
				swap((l_at(*begin_list, i2))->data,
						(l_at(*begin_list, i2 + 1))->data);
		i2 = 0;
		i1++;
	}
}
