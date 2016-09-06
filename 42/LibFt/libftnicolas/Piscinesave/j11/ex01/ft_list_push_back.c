/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:00:42 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/25 16:01:23 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list)
	{
		if ((*begin_list)->next)
			ft_list_push_back(&(*begin_list)->next, data);
		else
			(*begin_list)->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
