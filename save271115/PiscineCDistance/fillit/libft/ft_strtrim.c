/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:25:25 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 17:37:13 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*o;
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	while (ft_iswhite(s[i]) && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	len = ft_strlen((char *)s) - 1;
	while (ft_iswhite(s[len]))
		len--;
	if ((o = malloc(len + 2 - i)) == NULL)
		return (NULL);
	len = len + 1 - i;
	p = o;
	while (len--)
		*(o++) = s[i++];
	*o = '\0';
	return (p);
}
