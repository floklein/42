/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:03:32 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/08 18:17:28 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && str2[i] != 0)
	{
		str1[i] = str2[i];
		i++;
	}
	while (i < n)
	{
		str1[i] = 0;
		i++;
	}
	return (str1);
}
