/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:26:09 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/25 15:20:06 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	start = 0;
	end = 0;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
	{
		start++;
		if (s[start] == '\0')
			return (ft_strnew(0));
	}
	while (s[end])
		end++;
	end--;
	while (s[end] == '\n' || s[end] == '\t' || s[end] == ' ')
		end--;
	len = (end - start) + 1;
	str = ft_strnew(len);
	if (str)
		ft_strncpy(str, s + start, len);
	return (str);
}

char		*ft_strtrim(char const *s)
{
	if (s == NULL)
		return (NULL);
	return (trim(s));
}
