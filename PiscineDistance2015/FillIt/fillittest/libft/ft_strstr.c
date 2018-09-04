/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 14:59:25 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 21:19:50 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*(s1 + i))
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j)
		&& *(s1 + i + j) && *(s2 + j))
			j++;
		if (*(s2 + j) == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
