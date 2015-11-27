/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:25:15 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 17:47:37 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if ((*begin_list1) == NULL)
		(*begin_list1) = begin_list2;
	if ((*begin_list1)->next == NULL)
		(*begin_list1)->next = begin_list2;
	else
		ft_list_merge(&(*begin_list1)->next, begin_list2);
}
