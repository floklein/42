/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 19:07:25 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/06 12:39:26 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			if (new)
			{
				new->next = *alst;
				*alst = new;
			}
		}
	}
}
