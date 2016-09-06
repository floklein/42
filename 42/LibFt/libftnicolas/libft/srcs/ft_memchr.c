/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:19:02 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/23 15:16:09 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned const char	*s;
	unsigned char		unsigned_c;

	unsigned_c = (unsigned char)c;
	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == unsigned_c)
		{
			return ((void *)str);
		}
		i++;
		str++;
	}
	return (NULL);
}
