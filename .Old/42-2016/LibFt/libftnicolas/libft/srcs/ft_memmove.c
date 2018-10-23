/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:19:42 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:19:44 by nthibaud         ###   ########.fr       */
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
