/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 10:22:58 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:15:25 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i_dest;
	int i_src;

	i_src = 0;
	i_dest = 0;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (i_dest != ft_strlen(src) + ft_strlen(dest) && src[i_src] != '\0')
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	return (dest);
}

int		main(void)
{
	char s1[12] = "bite";
	char s2[4] = "poil";

	printf("%d", ft_strlen(s1));
	printf("%d", ft_strlen(s2));
	printf("%s", ft_strcat(s1, s2));
	return (0);
}
