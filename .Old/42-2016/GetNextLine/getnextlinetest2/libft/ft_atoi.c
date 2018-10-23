/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:57:32 by fklein            #+#    #+#             */
/*   Updated: 2016/04/20 18:56:31 by fklein           ###   ########.fr       */
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
