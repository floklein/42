/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:52:55 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 23:52:19 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_protos.h"

void	ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		ft_putchar(str[index]);
		index++;
	}
}