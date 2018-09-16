/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:03:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 20:45:36 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		is_operator(char *elem)
{
	return (ft_strlen(elem) == 1
			&& (*elem == '+' || *elem == '-' || *elem == '*' || *elem == '/'
				|| *elem == '%' || *elem == '(' || *elem == ')'));
}

int		find_priority(char *elem)
{
	if (elem == NULL)
		return (-1);
	else if (ft_strcmp(elem, "*") == 0 || ft_strcmp(elem, "/") == 0
			|| ft_strcmp(elem, "%") == 0)
		return (2);
	else if (ft_strcmp(elem, "+") == 0 || ft_strcmp(elem, "-") == 0)
		return (1);
	else if (ft_strcmp(elem, "(") == 0)
		return (0);
	return (-1);
}

char	**parse_polish(char **infix)
{
	int		size;
	char	**polish;
	char	**stack;
	int		i;
	int		k;

	size = find_size(infix);
	if (!(stack = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	k = 0;
	while (k < size)
		stack[k++] = NULL;
	if (!(polish = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
		polish[i++] = NULL;
	k = 0;
	i = 0;
	while (infix[i])
	{
		if (ft_strcmp(infix[i], ")") == 0)
		{
			while (ft_strcmp(top_stack(stack), "(") != 0)
				polish[k++] = de_stack(&stack);
			de_stack(&stack);
		}
		else if (is_operator(infix[i]))
		{
			if (ft_strcmp(infix[i], "(") == 0
					|| find_priority(infix[i]) > find_priority(top_stack(stack)))
				add_stack(&stack, infix[i]);
			else
			{
				while (find_priority(infix[i]) <= find_priority(top_stack(stack)))
				{
					if (!(ft_strcmp(top_stack(stack), "(") == 0
								|| ft_strcmp(top_stack(stack), ")") == 0))
						polish[k++] = ft_strdup(de_stack(&stack));
					else
						de_stack(&stack);
				}
				add_stack(&stack, infix[i]);
			}
		}
		else
			polish[k++] = ft_strdup(infix[i]);
		i++;
	}
	while ((polish[k] = de_stack(&stack)))
		k++;
	return (polish);
}
