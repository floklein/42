/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:23:04 by nthibaud          #+#    #+#             */
/*   Updated: 2016/03/03 19:26:08 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_switch(t_list **begin, t_list **middle, t_list **head)
{
	while (1)
	{
		(*middle)->next = *begin;
		if ((*head)->next == NULL)
			break ;
		*begin = *middle;
		*middle = *head;
		*head = (*head)->next;
	}
}

void	ft_two_nodes(t_list **begin_list)
{
	t_list	*tmp;

	tmp = (*begin_list)->data;
	(*begin_list)->data = (*begin_list)->next->data;
	(*begin_list)->next->data = tmp;
}

void	ft_data_switch(t_list **begin_list, t_list **head)
{
	t_list *tmp;

	tmp = (*begin_list)->data;
	(*begin_list)->data = (*head)->data;
	(*head)->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*begin;
	t_list	*middle;
	t_list	*head;
	t_list	*node_two;

	if (begin_list == NULL || begin_list->next == NULL)
		return ;
	if (begin_list->next->next == NULL)
	{
		ft_two_nodes(&begin_list);
		return ;
	}
	begin = begin_list;
	middle = begin_list->next;
	head = begin_list->next->next;
	node_two = begin_list->next;
	ft_switch(&begin, &middle, &head);
	ft_data_switch(&begin_list, &head);
	begin_list->next = middle;
	node_two->next = head;
	head->next = NULL;
}
