/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:29:49 by nthibaud          #+#    #+#             */
/*   Updated: 2016/03/16 12:40:55 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*i;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if (i->next)
		{
			if (cmp(i->next->data, data_ref) == 0)
			{
				tmp = i->next;
				i->next = tmp->next;
				free(tmp);
			}
		}
		if (i->next && cmp(i->next->data, data_ref) != 0)
			i = i->next;
	}
}
