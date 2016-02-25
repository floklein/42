/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 16:06:52 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/05 23:56:49 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = new;
	else
	{
		if ((*alst)->next)
			ft_lstadd_end(&((*alst)->next), new);
		else
			(*alst)->next = new;
	}
}
