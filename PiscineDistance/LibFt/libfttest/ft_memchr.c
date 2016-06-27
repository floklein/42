/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:02:27 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:02:29 by fklein           ###   ########.fr       */
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
