/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:49:59 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/15 20:00:40 by nsavry           ###   ########.fr       */
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
