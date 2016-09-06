/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:11 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/23 15:15:11 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *seek, size_t n)
{
	unsigned int	i;
	unsigned int	y;
	int				l;

	i = 0;
	l = 0;
	if (*seek == '\0')
		return ((char *)str);
	while (seek[l] != '\0')
		l++;
	while (str[i] != '\0')
	{
		y = 0;
		while (seek[y] == str[i + y] && i + y < n)
		{
			if (seek + y == seek + l - 1)
				return ((char *)str + (y + i) - (l - 1));
			y++;
		}
		i++;
	}
	return (NULL);
}
