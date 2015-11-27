/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:43:27 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/26 14:01:59 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static const char	*ft_size_not_zero(char *dest, const char *src, size_t size)
{
	while (*src != 0)
	{
		if (size > 1)
		{
			*dest++ = *src;
			size--;
		}
		src++;
	}
	*dest = 0;
	return (src);
}

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*src_cp;
	char		*dest_cp;
	size_t		size_cp;
	size_t		len;

	dest_cp = dest;
	src_cp = src;
	size_cp = size;
	len = size;
	while (*dest_cp != 0 && size_cp > 0)
	{
		dest_cp++;
		size_cp--;
	}
	len = dest_cp - dest;
	size_cp = size - len;
	if (size_cp == 0)
	{
		len = len + ft_strlen(src_cp);
		return (len);
	}
	src_cp = ft_size_not_zero(dest_cp, src_cp, size_cp);
	len = len + (src_cp - src);
	return (len);
}
