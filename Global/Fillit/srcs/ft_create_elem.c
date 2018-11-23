/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:51:05 by flklein           #+#    #+#             */
/*   Updated: 2018/11/23 18:45:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_create_elem(char *data)
{
	t_tetri	*node;

	if (!(node = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	node->next = NULL;
	node->piece = ft_strdup(data);
	node->placed = 0;
	return (node);
}
