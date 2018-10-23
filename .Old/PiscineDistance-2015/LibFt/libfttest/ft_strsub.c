/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:53 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:55 by fklein           ###   ########.fr       */
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
