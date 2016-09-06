/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:51:47 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 17:45:07 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str1;
	const char	*str2;

	i = 0;
	str1 = dest;
	str2 = src;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == c)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
