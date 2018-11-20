/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 01:58:13 by flklein           #+#    #+#             */
/*   Updated: 2018/11/20 18:42:01 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_push_back(t_tetri **begin_list, char *data)
{
	if (*begin_list)
	{
		if ((*begin_list)->next)
			ft_list_push_back(&((*begin_list)->next), data);
		else
			(*begin_list)->next = ft_create_elem(data);
	}
	else
		(*begin_list) = ft_create_elem(data);
}
