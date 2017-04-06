/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:03:19 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:03:22 by fklein           ###   ########.fr       */
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
