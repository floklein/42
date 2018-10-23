/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:36:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int		main(void)
{
	char tab[] = "poiUre";

	printf("%d", ft_str_is_alpha(tab));
	return (0);
}
