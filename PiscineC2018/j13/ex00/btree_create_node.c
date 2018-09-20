/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:37:23 by flklein           #+#    #+#             */
/*   Updated: 2018/09/19 15:37:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	if ((node = (t_btree*)malloc(sizeof(t_btree))))
	{
		node->left = NULL;
		node->right = NULL;
		node->item = item;
	}
	return (node);
}
