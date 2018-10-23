/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:39:14 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/25 09:30:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	int	result;

	result = 0;
	while (begin_list)
	{
		result = cmp(begin_list->data, data_ref);
		if (result == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
