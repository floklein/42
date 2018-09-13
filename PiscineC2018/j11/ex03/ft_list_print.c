/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:08:46 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 03:48:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);

#include <stdio.h>

void	ft_list_print(t_list *node)
{
	if (node)
		printf("%d\n", node->data);
	if (node->next)
		ft_list_print(node->next);
}

int		main(void)
{
	t_list	*list;

	list = NULL;
	list = ft_create_elem(32);
	ft_list_push_back(&list, 64);
	ft_list_push_back(&list, 100);
	ft_list_print(list);
	printf("%d\n", ft_list_size(list));
	return (0);
}
