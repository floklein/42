/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:02:27 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 18:31:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
