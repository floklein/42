/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:27:03 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 19:23:53 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		n--;
		i++;
	}
	while (n > 0)
	{
		*(dst + i) = '\0';
		i++;
		n--;
	}
	return (dst);
}
