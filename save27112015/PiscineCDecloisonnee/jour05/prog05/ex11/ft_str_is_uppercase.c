/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:46:01 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while ('A' <= str[i] && str[i] <= 'Z')
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int		main(void)
{
	char tab[] = "UYGUYGUYGOUYGOUYGOUYG";

	printf("%d", ft_str_is_uppercase(tab));
	return (0);
}
