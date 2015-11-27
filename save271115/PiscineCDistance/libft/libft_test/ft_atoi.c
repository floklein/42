/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:24 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/26 14:06:14 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int	ft_solve_atoi(const char *str, int nb, int i)
{
	while ((str[i] != 0) && (str[i] <= '9') && (str[i] >= '0'))
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}

int			ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		a;

	nb = 0;
	i = 0;
	a = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		i++;
		a = -1;
	}
	else if (str[i] == '+')
		i++;
	nb = ft_solve_atoi(str, nb, i);
	if (nb == 0)
		return (0);
	else
		return (nb * a);
}
