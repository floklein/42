/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 23:37:45 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:29:36 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		i++;
	}
	return (str);
}

int		main(void)
{
	char tab[] = "FloRent";

	printf("%s", ft_strlowcase(tab));
	return (0);
}
