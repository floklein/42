/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 00:01:05 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 16:24:00 by fklein           ###   ########.fr       */
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
