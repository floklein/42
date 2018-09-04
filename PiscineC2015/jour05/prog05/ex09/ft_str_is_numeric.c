/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:32:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int		main(void)
{
	char tab[] = "2345";

	printf("%d", ft_str_is_numeric(tab));
	return (0);
}
