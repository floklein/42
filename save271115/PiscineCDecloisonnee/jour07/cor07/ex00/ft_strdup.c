/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:41:48 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 18:34:47 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*cpy;

	index = 0;
	cpy = malloc(sizeof(char) * ft_strlen(src));
	while (*(src + index))
	{
		*(cpy + index) = *(src + index);
		index++;
	}
	return (cpy);
}
