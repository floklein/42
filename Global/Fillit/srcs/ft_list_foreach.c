/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:32:37 by flklein           #+#    #+#             */
/*   Updated: 2018/11/20 19:15:34 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_foreach(t_tetri *begin_list, void (*f)(const char *))
{
	if (!begin_list)
		return ;
	(*f)(begin_list->piece);
	if (begin_list->next)
		ft_list_foreach(begin_list->next, f);
}
