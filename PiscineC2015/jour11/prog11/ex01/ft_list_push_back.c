/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 13:22:55 by fklein            #+#    #+#             */
/*   Updated: 2015/11/03 21:45:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (!(*begin_list))
		(*begin_list) = ft_create_elem(data);
	if ((*begin_list)->next)
		ft_list_push_back(&((*begin_list)->next), data);
	else
		(*begin_list)->next = ft_create_elem(data);
}
