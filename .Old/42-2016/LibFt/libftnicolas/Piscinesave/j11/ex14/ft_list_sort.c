/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 19:18:56 by nthibaud          #+#    #+#             */
/*   Updated: 2016/03/03 19:21:49 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_start_list(t_list **begin_list, int (*cmp)(), t_list **start_list)
{
	if (cmp((*begin_list)->data, (*begin_list)->next->data) <= 0)
		*start_list = *begin_list;
	if (cmp((*begin_list)->data, (*begin_list)->next->data) > 0)
		*start_list = (*begin_list)->next;
}

int		ft_data_cmp(t_list **begin_list, t_list **tmp_prev, int (*cmp)())
{
	while (cmp((*begin_list)->data, (*begin_list)->next->data) <= 0)
	{
		*tmp_prev = *begin_list;
		*begin_list = (*begin_list)->next;
		if ((*begin_list)->next == NULL)
			return (0);
	}
	return (1);
}

void	ft_sort(t_list **begin_list, t_list **tmp_prev)
{
	t_list	*tmp_next;

	tmp_next = (*begin_list)->next;
	(*begin_list)->next = (*begin_list)->next->next;
	tmp_next->next = *begin_list;
	if (*tmp_prev != *begin_list)
		(*tmp_prev)->next = tmp_next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp_prev;
	t_list	*start_list;
	int		is_sort;

	is_sort = 1;
	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	while (is_sort != 0)
	{
		is_sort = 1;
		ft_start_list(begin_list, cmp, &start_list);
		tmp_prev = *begin_list;
		is_sort = ft_data_cmp(begin_list, &tmp_prev, cmp);
		if (is_sort != 0)
			ft_sort(begin_list, &tmp_prev);
		*begin_list = start_list;
	}
}
