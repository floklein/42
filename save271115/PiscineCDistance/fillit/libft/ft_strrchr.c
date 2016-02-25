/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:34:13 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 14:03:06 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	pos;
	size_t	found;

	pos = 0;
	found = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
		{
			found++;
			pos = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (found)
		return ((char *)s + pos);
	return (NULL);
}
