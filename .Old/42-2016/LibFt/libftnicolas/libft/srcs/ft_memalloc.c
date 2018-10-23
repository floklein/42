/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:18:46 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:18:47 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tab;
	char	*tmp;

	if ((tab = malloc(sizeof(*tab) * size)) == NULL)
		return (NULL);
	tmp = tab;
	while (size != 0)
	{
		size--;
		tmp[size] = 0;
	}
	return (tab);
}
