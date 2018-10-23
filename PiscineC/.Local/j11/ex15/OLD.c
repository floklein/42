/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:33:02 by flklein           #+#    #+#             */
/*   Updated: 2018/09/13 17:36:09 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list *begin_list)
{
	void	*tmp1;
	void	*tmp2;
	void	*tmp3;

	if (!(begin_list) || !((begin_list)->next))
		return ;
	tmp1 = *begin_list;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	while (tmp3)
	{
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
		tmp2->next = tmp1;
	}
	begin_list = tmp2;
}
