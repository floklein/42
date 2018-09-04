/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:34 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:35 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = ft_strlen(str);
	while ((len) != 0)
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
		len--;
	}
	if (str[0] == (char)c)
		return ((char *)str);
	return (NULL);
}
