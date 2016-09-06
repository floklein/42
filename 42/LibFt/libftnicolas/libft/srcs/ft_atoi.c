/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:16:54 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/16 11:17:30 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	pos_neg;
	int	nb;

	i = 0;
	pos_neg = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		pos_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] != 0) && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb == 0)
		return (0);
	return (nb * pos_neg);
}
