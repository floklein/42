/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:04:09 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/26 13:59:37 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_solvestr(const char *str, const char *seek)
{
	int		i1;
	int		i2;
	char	*ptr;

	i1 = 0;
	i2 = 0;
	while (str[i1] != 0)
	{
		while (str[i1] == seek[i2])
		{
			i1++;
			i2++;
			if (seek[i2] == 0)
			{
				ptr = (char *)&str[i1 - i2];
				return (ptr);
			}
		}
		i2 = 0;
		i1++;
	}
	return (NULL);
}

char		*ft_strstr(const char *str, const char *seek)
{
	char	*ptr;

	if (!(*seek))
		ptr = (char *)str;
	else
		ptr = ft_solvestr(str, seek);
	return (ptr);
}
