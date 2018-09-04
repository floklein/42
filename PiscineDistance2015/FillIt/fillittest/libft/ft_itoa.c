/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:57:22 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 17:46:18 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(long n, size_t sign)
{
	size_t	size;

	size = sign + ((n == 0) ? 1 : 0);
	n = (n < 0) ? n * -1 : n;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	size_t	i;
	size_t	sign;

	nbr = (long)n;
	sign = (n < 0) ? 1 : 0;
	nbr = (sign == 1) ? -1 * nbr : nbr;
	i = ft_getsize(nbr, sign);
	if ((result = malloc(i + 1)) == NULL)
		return (NULL);
	result[i] = '\0';
	while (i-- != sign)
	{
		result[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	result[0] = (sign == 1) ? '-' : result[0];
	return (result);
}
