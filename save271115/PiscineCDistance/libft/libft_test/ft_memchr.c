/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:42:55 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/26 14:04:20 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n != 0)
	{
		if (*(unsigned char *)str == (unsigned char)c)
			return ((unsigned char*)str);
		str++;
		n--;
	}
	if (*(unsigned char *)str == (unsigned char)c)
		return ((unsigned char *)str);
	return (NULL);
}
