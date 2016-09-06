/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:14:22 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/25 17:04:01 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (begin_list)
	{
		if (count == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		count++;
	}
	return (begin_list);
}
