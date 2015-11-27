/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:07:28 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/30 14:35:42 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
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
