/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/28 20:50:33 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z' &&
				((str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
				(str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
				(str[i - 1] >= '0' && str[i - 1] <= '9')))
		{
			str[i] = str[i] + 32;
		}
		else if ('a' <= str[i] && str[i] <= 'z' &&
				((str[i - 1] < 'A' || str[i - 1] > 'Z') &&
				(str[i - 1] < 'a' || str[i - 1] > 'z') &&
				(str[i - 1] < '0' || str[i - 1] > '9')))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int		main()
{
	char tabc[] = "COUCOU coMment 3ca va";
	printf("%s", ft_strcapitalize(tabc));
}