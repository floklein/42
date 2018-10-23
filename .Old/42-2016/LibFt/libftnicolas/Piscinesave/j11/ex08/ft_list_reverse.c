/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:16:01 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/25 16:17:20 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp_next;
	t_list	*tmp_prev;

	if (*begin_list != NULL && (*begin_list)->next != NULL)
	{
		tmp_next = (*begin_list)->next;
		tmp_prev = *begin_list;
		(*begin_list)->next = NULL;
		while (tmp_next != NULL)
		{
			*begin_list = tmp_next;
			tmp_next = (*begin_list)->next;
			(*begin_list)->next = tmp_prev;
			tmp_prev = *begin_list;
		}
	}
}
