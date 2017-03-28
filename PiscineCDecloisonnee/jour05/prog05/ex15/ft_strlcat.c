/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:13:03 by fklein            #+#    #+#             */
/*   Updated: 2015/10/23 14:23:07 by fklein           ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char *dest_copy = dest;
	char *src_copy = src;
	unsigned int len_dest;
	unsigned int size_copy;

	size_copy = size;
	while (*(dest_copy) && size-- != 0)
		dest_copy++;
	len_dest = dest_copy - dest;
	size_copy = size - len_dest;
	if (size_copy == 0)
		return (len_dest + ft_strlen(src));
	while (*src_copy)
	{
		if (size_copy != 1)
		{
			*dest_copy++ = *src_copy;
			size_copy--;
		}
		src_copy++;
	}
	return (len_dest + (src_copy - src));
}

int		main(void)
{
	char destination[] = "salut";
	char source[] = "bonjour";

	printf("attendu:%lu", strlcat(destination, source, 1));
	printf("resultat:%d", ft_strlcat(destination, source, 1));
}
