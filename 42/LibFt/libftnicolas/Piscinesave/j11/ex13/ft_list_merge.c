/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:43:50 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/25 17:52:33 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*tmp;

	if (*begin_list1 == NULL && begin_list2 != NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (begin_list2 != NULL && begin_list1 != NULL)
	{
		tmp = *begin_list1;
		while ((*begin_list1)->next)
			*begin_list1 = (*begin_list1)->next;
		(*begin_list1)->next = begin_list2;
		*begin_list1 = tmp;
	}
}
