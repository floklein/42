/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 23:22:35 by flklein           #+#    #+#             */
/*   Updated: 2018/09/14 01:37:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *node, int (*cmp)())
{
	t_list	*tmp;

	if (!(*begin_list))
	{
		*begin_list = node;
		node->next = NULL;
	}
	else if ((*cmp)((*begin_list)->data, node->data) < 0)
		ft_sorted_list_insert(&((*begin_list)->next), node, cmp);
	else
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = node;
		(*begin_list)->next->next = tmp;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	while (begin_list2)
	{
		ft_sorted_list_insert(begin_list1, begin_list2, cmp);
		begin_list2 = begin_list2->next;
	}
}
