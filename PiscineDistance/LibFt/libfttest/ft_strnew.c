/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:19 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:21 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(*ptr) * (size + 1));
	if (ptr)
	{
		while (size)
		{
			ptr[size] = 0;
			size--;
		}
		ptr[0] = 0;
	}
	return (ptr);
}
