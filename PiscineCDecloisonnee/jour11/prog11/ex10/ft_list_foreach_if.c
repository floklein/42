/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:26:04 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 22:11:35 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach_if(t_list *begin_list,
		void (*f)(void *), void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return;
	if ((*cmp)(begin_list->data, data_ref) == 0)
		f(begin_list->data);
	if (begin_list->next)
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}
