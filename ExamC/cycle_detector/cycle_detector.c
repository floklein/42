/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:03:33 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 10:07:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		cycle_detector(const t_list *list)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = (t_list *)list;
	while (cur)
	{
		i++;
		if (i > 5000)
			return (1);
		cur = cur->next;
	}
	return (0);
}
