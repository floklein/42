/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:39:03 by flklein           #+#    #+#             */
/*   Updated: 2018/09/19 15:39:05 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*tmp;

	tmp = NULL;
	if (root == NULL)
		return (NULL);
	if (root->left != NULL)
		tmp = btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (tmp == NULL && root->right != NULL)
		tmp = btree_search_item(root->right, data_ref, cmpf);
	return (tmp);
}
