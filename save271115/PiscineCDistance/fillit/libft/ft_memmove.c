/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:41:14 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 17:45:39 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 3;
	if (src <= dst && src + len >= dst)
		i = 1;
	d = (i == 1) ? d + len - 1 : d;
	s = (i == 1) ? s + len - 1 : s;
	while (len--)
	{
		*d = *s;
		d += i - 2;
		s += i - 2;
	}
	return (dst);
}
