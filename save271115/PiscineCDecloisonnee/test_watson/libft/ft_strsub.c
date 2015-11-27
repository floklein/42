/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:31:07 by nsavry            #+#    #+#             */
/*   Updated: 2013/11/30 14:35:15 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t n)
{
	char	*tmp;

	tmp = ft_strnew(n);
	if (tmp)
		ft_strncpy(tmp, str + start, n);
	return (tmp);
}
