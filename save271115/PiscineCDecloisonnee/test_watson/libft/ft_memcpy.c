/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:03:32 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/30 14:27:27 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned long	i;
	char			*temp1;
	const char		*temp2;

	i = 0;
	temp1 = str1;
	temp2 = str2;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (str1);
}
