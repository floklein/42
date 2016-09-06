/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:24:31 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:24:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	max;

	i = 0;
	max = ft_strlen(src);
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (max < n)
	{
		while (max < n)
		{
			dst[max] = '\0';
			max++;
		}
	}
	return (dst);
}
