/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 17:02:42 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 16:31:11 by fklein           ###   ########.fr       */
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
