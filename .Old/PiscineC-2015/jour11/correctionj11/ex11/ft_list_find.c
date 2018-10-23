/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:48:16 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 22:13:14 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return (NULL);
	if ((*cmp)(begin_list->data, data_ref) == 0)
		return (begin_list);
	else if (begin_list->next)
		return (ft_list_find(begin_list->next, data_ref, cmp));
	else
		return (NULL);
}
