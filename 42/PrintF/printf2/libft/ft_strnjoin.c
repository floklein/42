/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:24 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:25 by fklein           ###   ########.fr       */
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
