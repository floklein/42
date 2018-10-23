/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:41 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:25:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *str, const char *seek)
{
	int	i;
	int	y;
	int	l;

	i = 0;
	l = 0;
	if (*seek == '\0')
		return ((char *)str);
	while (seek[l] != '\0')
		l++;
	while (str[i] != '\0')
	{
		y = 0;
		while (seek[y] == str[i + y])
		{
			if (seek + y == seek + l - 1)
				return ((char *)str + (y + i) - (l - 1));
			y++;
		}
		i++;
	}
	return (NULL);
}
