/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:27:45 by fklein            #+#    #+#             */
/*   Updated: 2016/04/20 18:28:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_list	*ft_create_elem(void)
{
	t_list *node;

	if ((node = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	node->next = NULL;
	node->c = '0';
	return (node);
}

void	ft_list_push_back(t_list **root)
{
	if (*root)
	{
		if ((*root)->next)
			ft_list_push_back(&((*root)->next));
		else
			(*root)->next = ft_create_elem();
	}
	else
		*root = ft_create_elem();
}

void	ft_destroy(t_list *root)
{
	if (root)
	{
		ft_destroy(root->next);
		free(root);
	}
}

char	*ft_list_to_tab(t_list *root, int deep)
{
	char	*s;
	int		i;
	t_list	*node;

	if ((s = (char *)malloc(sizeof(char) * (deep + 1))) == NULL)
		return (NULL);
	i = -1;
	node = root;
	while (++i < deep)
	{
		s[i] = node->c;
		node = node->next;
	}
	ft_destroy(root);
	s[deep] = '\0';
	return (s);
}
