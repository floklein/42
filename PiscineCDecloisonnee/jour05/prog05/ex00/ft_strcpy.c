/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 18:03:48 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:24:35 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (*(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	return (dest);
}

int		main(void)
{
	char src[] = "Hello";
	char dest[] = "World";

	printf("%s | %s", src, ft_strcpy(dest, src));
}
