/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:02:52 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/02 15:21:11 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t n)
{
	void	*s;

	s = malloc(sizeof(*s) * n);
	if (!s)
		return (s);
	if (s)
	{
		ft_bzero(s, n);
		return (s);
	}
	else
		return (NULL);
}
