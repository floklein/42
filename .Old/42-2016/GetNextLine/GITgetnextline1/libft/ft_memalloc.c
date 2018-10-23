/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:02:08 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:02:13 by fklein           ###   ########.fr       */
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
