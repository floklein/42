/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:39:26 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 19:33:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *node;

	node = ft_create_elem(data);
	if ((*begin_list))
		node->next = *begin_list;
	*begin_list = node;
}

t_list *ft_list_push_params(int ac, char **av)
{
	t_list		*node;
	int			index;

	node = NULL;
	index = -1;
	if (ac)
		while (++index < ac)
			ft_list_push_front(&node, av[index]);
	return (node);
}
