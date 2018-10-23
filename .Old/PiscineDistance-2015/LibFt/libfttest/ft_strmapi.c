/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:30 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:32 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	size_t	i;

	i = 0;
	t = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		t[i] = f(i, s[i]);
		i++;
	}
	return (t);
}
