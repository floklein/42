/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:49:34 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 18:50:13 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*begin;

	begin = *alst;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = (*alst)->next;
	(*alst)->next = NULL;
	*alst = begin;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*node;

	new_lst = NULL;
	if (lst != NULL)
	{
		new_lst = f(lst);
		lst = lst->next;
	}
	while (lst != NULL)
	{
		node = f(lst);
		ft_lstaddlast(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
