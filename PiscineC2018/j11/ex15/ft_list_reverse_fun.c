/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:15:26 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 22:47:36 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list)
		return (NULL);
	else if (nbr == 0)
		return (begin_list);
	else if (begin_list->next)
		return (ft_list_at(begin_list->next, nbr - 1));
	else
		return (NULL);
}

void	ft_swap_data(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		ft_swap_data(&((ft_list_at(begin_list, i))->data),
				&(ft_list_at(begin_list, size - i - 1)->data));
		i++;
	}
}
