/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:50:47 by flklein           #+#    #+#             */
/*   Updated: 2018/09/17 12:02:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	my_ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else if (!((*begin_list1)->next))
		(*begin_list1)->next = begin_list2;
	else
		my_ft_list_merge(&((*begin_list1)->next), begin_list2);
}

void	my_ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;
	void	*min;

	tmp1 = *begin_list;
	while (tmp1)
	{
		tmp3 = tmp1;
		min = tmp1->data;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if ((*cmp)(min, tmp2->data) > 0)
			{
				tmp3 = tmp2;
				min = tmp3->data;
			}
			tmp2 = tmp2->next;
		}
		tmp3->data = tmp1->data;
		tmp1->data = min;
		tmp1 = tmp1->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	elem = ft_create_elem(data);
	my_ft_list_merge(begin_list, elem);
	my_ft_list_sort(begin_list, cmp);
}
