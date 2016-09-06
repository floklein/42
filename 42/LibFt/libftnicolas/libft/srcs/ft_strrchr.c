/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:22 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:35:46 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			tmp = (char *)str;
		str++;
	}
	if (*str == c)
		tmp = (char *)str;
	return (tmp);
}
