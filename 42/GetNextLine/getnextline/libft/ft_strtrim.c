/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:10:16 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 18:36:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*trim(const char *str)
{
	size_t			len;
	size_t			n;
	unsigned int	start;
	char			*tmp;
	char			*d;

	start = 0;
	while (str[start] == ' ' || str[start] == '\n' || str[start] == '\t')
	{
		start++;
		if (str[start] == 0)
		{
			d = ft_strnew(0);
			return (d);
		}
	}
	len = ft_strlen(str);
	n = len - 1;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t')
		n--;
	tmp = ft_strnew(n - start + 1);
	if (!tmp)
		return (tmp);
	tmp = ft_memcpy(tmp, str + start, n - start + 1);
	return (tmp);
}

char			*ft_strtrim(const char *str)
{
	if (!str)
		return (NULL);
	return (trim(str));
}
