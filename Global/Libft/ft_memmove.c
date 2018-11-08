/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:02:28 by flklein           #+#    #+#             */
/*   Updated: 2018/11/08 14:05:55 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((unsigned char *)src < (unsigned char *)dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
