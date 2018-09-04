/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:54:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/04 17:00:43 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len++]);
	return (len - 1);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc(ft_strlen(src) * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
