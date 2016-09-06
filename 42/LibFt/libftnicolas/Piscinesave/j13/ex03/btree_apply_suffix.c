/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:46:14 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/12 18:46:16 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left != 0)
			btree_apply_suffix(root->left, applyf);
		if (root->right != 0)
			btree_apply_suffix(root->right, applyf);
		applyf(root->item);
	}
}
