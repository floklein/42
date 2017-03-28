/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:25:41 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 19:20:18 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	if (*begin_list != NULL)
	{
		ft_list_clear(&((*begin_list)->next));
		free(*begin_list);
		*begin_list = NULL;
	}
}

/* -----------------------FONCTION DE TEST-------------------------*/

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

t_list	*ft_create_elem(char *data)
{
	t_list	*node;

	if ((node = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	node->next = NULL;
	node->data = data;
	return (node);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if ((*begin_list)->next)
		ft_list_push_back(&((*begin_list)->next), data);
	else
		(*begin_list)->next = ft_create_elem(data);
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		index;
	t_list	*root;

	root = NULL;
	index = 1;
	if (ac > 1)
		if ((root = ft_create_elem(av[1])) != NULL)
			while (++index < ac)
				ft_list_push_back(&root, av[index]);
	return (root);
}

int		main(int ac, char **av)
{
	t_list	*test;

	test = ft_list_push_params(ac, av);
	ft_print_list(test);
	ft_list_clear(&test);
	printf("\nCleared ?\n");
	ft_print_list(test);
}
