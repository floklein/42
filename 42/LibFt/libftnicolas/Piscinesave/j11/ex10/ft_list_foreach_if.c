/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:44:41 by nthibaud          #+#    #+#             */
/*   Updated: 2016/05/23 20:23:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	int	result;

	result = 0;
	while (begin_list)
	{
		result = cmp(begin_list->data, data_ref);
		if (result == 0)
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
