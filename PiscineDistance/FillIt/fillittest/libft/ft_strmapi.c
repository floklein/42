/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:00:54 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 23:29:25 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*o;
	size_t	i;

	i = 0;
	if ((o = malloc(1 + ft_strlen((char *)s))) == NULL)
		return (NULL);
	while (s[i])
	{
		o[i] = f(i, s[i]);
		i++;
	}
	o[i] = '\0';
	return (o);
}
