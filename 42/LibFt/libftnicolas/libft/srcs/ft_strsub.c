/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:51 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/25 14:51:33 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*section;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	section = ft_strnew(len);
	if (section)
		ft_strncpy(section, s + start, len);
	return (section);
}
