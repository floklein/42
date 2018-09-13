/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 01:58:13 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 01:59:13 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
		ft_list_push_back(&((*begin_list)->next), data);
	else
		(*begin_list) = ft_create_elem(data);
}
