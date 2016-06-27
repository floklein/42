/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:01 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:03 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	if (tmp)
	{
		ft_strcpy(tmp, str1);
		ft_strcpy(tmp + ft_strlen(str1), str2);
	}
	return (tmp);
}
