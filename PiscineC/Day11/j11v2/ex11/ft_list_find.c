/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:53:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 12:57:02 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	if (!begin_list)
		return (NULL);
	else if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	else
		return (ft_list_find(begin_list->next, data_ref, cmp));
}
