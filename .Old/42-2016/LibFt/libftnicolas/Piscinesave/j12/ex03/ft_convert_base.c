/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:38:20 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:42:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int		ft_iterative_power(int nb, int power)
{
	int count;

	count = nb;
	if (power == 0)
		return (1);
	if (power > 0)
	{
		while (power > 1)
		{
			nb = nb * count;
			power--;
		}
		return (nb);
	}
	else
		return (0);
}

int		ft_base_ten(char *nbr, char *base_from)
{
	int nb;
	int nbr_len;
	int i;
	int j;

	nb = 0;
	i = 0;
	j = 0;
	nbr_len = ft_strlen(nbr) - 1;
	while (nbr[i] != '\0')
	{
		j = 0;
		while (nbr[i] != base_from[j])
		{
			if (base_from[j + 1] == '\0')
				return (-1);
			j++;
		}
		nb = nb + j * ft_iterative_power(ft_strlen(base_from), nbr_len);
		nbr_len--;
		i++;
	}
	return (nb);
}

void	ft_base_to(char *nbr, char *base_to, int nb, int size)
{
	int i;
	int j;
	int end;

	end = size;
	j = 0;
	while (end > j)
	{
		i = nb % ft_strlen(base_to);
		nb = nb / ft_strlen(base_to);
		nbr[size - 1] = base_to[i];
		size--;
		j++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		nb_tmp;
	int		size;
	int		result;

	result = 1;
	nb = ft_base_ten(nbr, base_from);
	if (nb == -1)
		return (nbr);
	nb_tmp = nb;
	size = 0;
	while (result != 0)
	{
		nb_tmp = nb_tmp / ft_strlen(base_to);
		result = nb_tmp;
		size++;
	}
	nbr = (char*)malloc(sizeof(nbr) * (size + 1));
	ft_base_to(nbr, base_to, nb, size);
	nbr[size] = '\0';
	return (nbr);
}
