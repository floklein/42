/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:14:56 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/08 18:17:42 by nsavry           ###   ########.fr       */
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
