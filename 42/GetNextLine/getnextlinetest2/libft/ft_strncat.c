/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:36 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:38 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (str1[a] != 0)
		a++;
	while (b < n && str2[b] != 0)
	{
		str1[a] = str2[b];
		a++;
		b++;
	}
	str1[a] = 0;
	return (str1);
}
