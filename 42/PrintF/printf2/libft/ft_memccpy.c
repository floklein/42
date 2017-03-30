/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:02:20 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:02:23 by fklein           ###   ########.fr       */
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
