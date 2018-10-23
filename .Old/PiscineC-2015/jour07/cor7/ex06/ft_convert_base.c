/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 21:23:21 by fklein            #+#    #+#             */
/*   Updated: 2015/10/31 21:29:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power > 0)
		return (nb * ft_power(nb, power - 1));
	else
		return (0);
}

int		ft_size(int v, int b)
{
	int		size;

	size = 0;
	while (ft_power(b, size) <= v)
		size++;
	return (size);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		nb;
	int		size;

	nb = 0;
	i = - 1;
	while (nbr[++i])
	{
		j = - 1;
		while (base_from[++j] != nbr[i])
			if (base_from[j + 1] == '\0')
				return (nbr);
		nb = nb * ft_strlen(base_from) + j;
	}
	size = ft_size(nb, ft_strlen(base_to));
	nbr = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i++ < size)
	{
		nbr[size - i] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
	}
	nbr[size] = '\0';
	return (nbr);
}
