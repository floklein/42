/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:22 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 17:45:25 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	int		i;

	i = 0;
	if (s && f)
	{
		if ((t = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (s[i] != 0)
		{
			t[i] = f(s[i]);
			i++;
		}
		return (t);
	}
	return (NULL);
}
