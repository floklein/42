/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 20:58:47 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 15:35:04 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_glob.h"
#include "ft_make_tree.h"

t_node	*create_node(char *s, t_node *left, t_node *right)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->ls = left;
	node->rs = right;
	node->val = s;
	return (node);
}

void	ft_deforestation(t_node *tree)
{
	if (tree->rs != NULL)
		ft_deforestation(tree->rs);
	if (tree->ls != NULL)
		ft_deforestation(tree->ls);
	free(tree->val);
	free(tree);
}

t_node	*make_tree(char *str)
{
	int		i;
	char	*c;

	str = ft_strip_pth(str);
	i = index_lowest_op(str);
	if (i < 0)
	{
		return (create_node(str, NULL, NULL));
	}
	c = malloc(sizeof(*c));
	c[0] = str[i];
	c[1] = '\0';
	str[i] = '\0';
	return (create_node((c), make_tree(str), make_tree(str + i + 1)));
	free(c);
}

int		index_lowest_op(char *str)
{
	int		i;
	int		o;
	int		pth_lvl;

	o = 0;
	pth_lvl = 0;
	while (g_ope[o])
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '(')
				pth_lvl++;
			if (str[i] == ')')
				pth_lvl--;
			if (g_ope[o] == str[i] && pth_lvl == 0)
				return (i);
			i++;
		}
		o++;
	}
	return (-1);
}

int		ft_calc_tree(t_node *tree)
{
	int		i;
	char	c;

	if (tree->ls == NULL && tree->rs == NULL)
	{
		i = ft_atoi(tree->val);
		return (i);
	}
	i = 0;
	c = tree->val[0];
	while (g_ope[i] != c)
		i++;
	i = g_ops[i](ft_calc_tree(tree->ls), ft_calc_tree(tree->rs));
	return (i);
}
