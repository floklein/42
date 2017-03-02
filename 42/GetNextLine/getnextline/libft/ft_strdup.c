/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:07:32 by fklein            #+#    #+#             */
/*   Updated: 2016/07/25 17:11:12 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dup;

	len = ft_strlen(str);
	if ((dup = (char *)malloc(sizeof(*dup) * (len + 1))) == NULL)
		return (NULL);
	dup = ft_strcpy(dup, str);
	return (dup);
}
