/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 18:03:48 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:26:58 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;
	unsigned int len_src;

	index = 0;
	len_src = ft_strlen(src);
	while (*(dest + index))
	{
		if (index <= n || n <= len_src)
			*(dest + index) = *(src + index);
		else
			*(dest + index) = '\0';
		index++;
	}
	return (dest);
}

int		main(void)
{
	char src[] = "Hello";
	char dest[] = "Flo";

	printf("%s | %s", src, ft_strncpy(dest, src, 7));
}
