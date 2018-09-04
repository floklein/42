/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:29 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:30 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_solve_nstr(const char *str, const char *seek, size_t n)
{
	int				i1;
	unsigned int	i2;
	char			*ptr;

	i1 = 0;
	i2 = 0;
	while (str[i1] != 0)
	{
		while ((str[i1] == seek[i2]) && (i2 < n))
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

char		*ft_strnstr(const char *str, const char *seek, size_t n)
{
	char	*ptr;

	if (!(*seek))
		ptr = (char *)str;
	else
		ptr = ft_solve_nstr(str, seek, n);
	return (ptr);
}
