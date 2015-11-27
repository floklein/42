/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:42:39 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/04 14:49:48 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *str1, const char *str2, size_t n)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str1) + n);
	if (tmp)
	{
		ft_strcpy(tmp, str1);
		ft_strncpy(tmp + ft_strlen(str1), str2, n);
	}
	return (tmp);
}
