/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:18:00 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/08 18:17:38 by nsavry           ###   ########.fr       */
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
