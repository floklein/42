/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_lastpos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:47:18 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 18:47:51 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_lastpos(t_list **lst, t_list *newnode)
{
	t_list *begin;

	begin = *lst;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = newnode;
	*lst = (*lst)->next;
	(*lst)->next = NULL;
	*lst = begin;
}
