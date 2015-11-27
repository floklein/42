/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:42:25 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/28 14:23:14 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n != 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		n--;
		if (*(unsigned char *)src == (unsigned char)c)
			return (++dest);
		dest++;
		src++;
	}
	return (NULL);
}
