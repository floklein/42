/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:40:38 by flklein           #+#    #+#             */
/*   Updated: 2018/11/20 18:42:29 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_list_at(t_tetri *begin_list, unsigned int nbr)
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
