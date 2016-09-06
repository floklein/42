/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:09:56 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/25 17:50:31 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	list = NULL;
	tmp = NULL;
	i = ac - 1;
	if (ac > 0)
	{
		list = ft_create_elem(av[i]);
		tmp = list;
		i--;
		while (i >= 0)
		{
			list->next = ft_create_elem(av[i]);
			list = list->next;
			i--;
		}
	}
	return (tmp);
}
