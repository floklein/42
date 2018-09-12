/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:08:46 by flklein           #+#    #+#             */
/*   Updated: 2018/09/12 16:13:20 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_print(t_list *node)
{
	if (node)
		ft_printf("%d\n", node->data);
	if (node->next)
		ft_list_print(node->next);
}
