/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:03:34 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:03:37 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = str1;
	src = str2;
	if (str2 <= str1)
	{
		while (n > 0)
		{
			n--;
			dest[n] = src[n];
		}
	}
	else
		ft_memcpy(str1, str2, n);
	return (dest);
}
