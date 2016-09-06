/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:01:59 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/18 18:02:01 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	if ((result = malloc(sizeof(int) * length)) == NULL)
		return (0);
	i = 0;
	while (i <= length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
