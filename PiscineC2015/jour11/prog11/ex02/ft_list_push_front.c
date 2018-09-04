/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 13:40:45 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 21:47:26 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *node;
	
	if (node = ft_create_elem(data))
		node->next = *begin_list;
	*begin_list = node;
}
