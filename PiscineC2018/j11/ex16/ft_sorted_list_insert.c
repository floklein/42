/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:50:47 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 23:02:29 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*tmp;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else if ((*cmp)((*begin_list)->data, data) > 0)
		ft_sorted_list_insert(&((*begin_list)->next), data, cmp);
	else
	{
		tmp = (*begin_list)->next;
		*begin_list = 
	}
}
