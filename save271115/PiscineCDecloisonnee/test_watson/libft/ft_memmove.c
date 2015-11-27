/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:42:39 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/30 14:29:23 by nsavry           ###   ########.fr       */
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
