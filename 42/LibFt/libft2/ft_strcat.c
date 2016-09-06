/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:06:48 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:06:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcat(char *str1, const char *str2)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str1[a] != 0)
		a++;
	while (str2[b] != 0)
	{
		str1[a] = str2[b];
		a++;
		b++;
	}
	str1[a] = 0;
	return (str1);
}
