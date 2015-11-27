/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:42:39 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/28 15:10:47 by nsavry           ###   ########.fr       */
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
