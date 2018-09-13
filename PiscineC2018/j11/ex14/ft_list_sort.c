/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:20:52 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 17:06:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;
	void	*min;

	tmp1 = *begin_list;
	while (tmp1)
	{
		tmp3 = tmp1;
		min = tmp1->data;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if ((*cmp)(min, tmp2->data) > 0)
			{
				tmp3 = tmp2;
				min = tmp3->data;
			}
			tmp2 = tmp2->next;
		}
		tmp3->data = tmp1->data;
		tmp1->data = min;
		tmp1 = tmp1->next;
	}
}
