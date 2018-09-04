/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 19:11:54 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 19:21:31 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*root;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	if ((root = f(lst)) == NULL)
		return (NULL);
	node = root;
	while (lst->next)
	{
		lst = lst->next;
		if ((node->next = f(lst)) == NULL)
			return (NULL);
		node = node->next;
	}
	node->next = NULL;
	return (root);
}
