/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:51:57 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/12 19:37:56 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*ret;

	ret = NULL;
	if (root == NULL)
		return (NULL);
	if (root->left != NULL)
		ret = btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (ret == NULL && root->right != NULL)
		ret = btree_search_item(root->right, data_ref, cmpf);
	return (ret);
}
