/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:51:01 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 18:52:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_start_list(t_list **begin_list,
			int (*cmp)(), t_list **start_list)
{
	if (cmp((*begin_list)->content, (*begin_list)->next->content) <= 0)
		*start_list = *begin_list;
	if (cmp((*begin_list)->content, (*begin_list)->next->content) > 0)
		*start_list = (*begin_list)->next;
}

static int	ft_content_cmp(t_list **begin_list, t_list **tmp_prev, int (*cmp)())
{
	while (cmp((*begin_list)->content, (*begin_list)->next->content) <= 0)
	{
		*tmp_prev = *begin_list;
		*begin_list = (*begin_list)->next;
		if ((*begin_list)->next == NULL)
			return (0);
	}
	return (1);
}

static void	ft_sort(t_list **begin_list, t_list **tmp_prev)
{
	t_list	*tmp_next;

	tmp_next = (*begin_list)->next;
	(*begin_list)->next = (*begin_list)->next->next;
	tmp_next->next = *begin_list;
	if (*tmp_prev != *begin_list)
		(*tmp_prev)->next = tmp_next;
}

void		ft_lstsort_content(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp_prev;
	t_list	*start_list;
	int		is_sort;

	is_sort = 1;
	while (is_sort != 0)
	{
		is_sort = 1;
		ft_start_list(begin_list, cmp, &start_list);
		tmp_prev = *begin_list;
		is_sort = ft_content_cmp(begin_list, &tmp_prev, cmp);
		if (is_sort != 0)
			ft_sort(begin_list, &tmp_prev);
		*begin_list = start_list;
	}
}
