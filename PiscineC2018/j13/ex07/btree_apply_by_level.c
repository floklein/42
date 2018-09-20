/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:47:02 by flklein           #+#    #+#             */
/*   Updated: 2018/09/20 13:18:11 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_tree	*tree;

	tree = root;
	while ()
	{
		btree_apply_suffix(tree->left, applyf);
		btree_apply_suffix(tree->right, applyf);
		applyf(tree->item);
		tree = tree->next;
	}
}
