/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:13:03 by fklein            #+#    #+#             */
/*   Updated: 2015/10/23 16:47:04 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char *dest_adress = dest;
	const char *src_adress = src;
	unsigned int size_copy = size;

	if (size_copy != 0 && --size_copy != 0)
	{
		if ((*dest_adress++ = *src_adress++) == 0)
			return (0);
	}
	while (size_copy != 0)
		size_copy--;
	if (size_copy == 0)
	{
		if (size != 0)
			*dest_adress = '\0';
		while (*src_adress++)
			;
	}
	return (src_adress - src - 1);
}

int		main(void)
{
	char destination[] = "bjrbjr";
	char source[] = "bonjourbonjour";

	printf("attendu:%lu", strlcpy(destination, source,5));
	printf("resultat:%d", ft_strlcpy(destination, source, 5));
}
