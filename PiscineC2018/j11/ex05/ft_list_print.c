/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:08:46 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 03:55:13 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_push_params(int ac, char **av);

#include <stdio.h>

void	ft_list_print(t_list *node)
{
	if (node)
		printf("%s\n", node->data);
	if (node->next)
		ft_list_print(node->next);
}

int		main(int ac, char **av)
{
	t_list	*list;

	list = ft_list_push_params(ac, av);
	ft_list_print(list);
	return (0);
}
