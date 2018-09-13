/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:15:26 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 22:18:23 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*new_list;
	t_list	*next_list;

	new_list = NULL;
	while (begin_list)
	{
		next_list = begin_list->next;
		begin_list->next = new_list;
		new_list = begin_list;
		begin_list = next_list;
	}
	begin_list = new_list;
}
