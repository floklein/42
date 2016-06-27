/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:19:49 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 11:30:45 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	size_t n;

	n = 0;
	while ((dst[n] = src[n]) != '\0')
		n++;
	return (dst);
}
