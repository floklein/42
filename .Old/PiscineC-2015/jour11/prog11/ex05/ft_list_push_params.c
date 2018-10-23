/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:39:26 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 21:24:11 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>


void	ft_print_list(t_list	*root)
{
	while (root)
	{
		printf("%p | ",root);
		printf("%s", root->data);
		printf(" | %p\n", root->next);
		root = root->next;
	}
}

#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*el;

	if ((el = (t_list*)malloc(sizeof(t_list))))
	{
		el->data = data;
		el->next = NULL;
	}
	return (el);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *list;

	list = ft_create_elem(data);
	if ((*begin_list))
		list->next = *begin_list;
	*begin_list = list;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	while (++i < ac)
		ft_list_push_front(&list, av[i]);
	return (list);
}

int		main(int ac, char **av)
{
	ft_print_list(ft_list_push_params(ac, av));
}
