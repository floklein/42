/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:48 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:50 by fklein           ###   ########.fr       */
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
