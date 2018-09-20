/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:13:15 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 11:17:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list)
		return (NULL);
	else if (nbr == 0)
		return (begin_list);
	else if (begin_list->next)
		return (ft_list_at(begin_list->next, nbr - 1));
	else
		return (NULL);
}
