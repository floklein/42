/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:42:13 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 14:46:52 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)())
{
	t_list	*i_want_to_break_free;

	if (*begin_list)
	{
		if ((*cmp)((*begin_list)->data, data_ref) == 0)
		{
			i_want_to_break_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(i_want_to_break_free);
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
			ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
	}
}
