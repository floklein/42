/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:29 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 19:53:34 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
