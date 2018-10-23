/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:43 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:44 by fklein           ###   ########.fr       */
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
