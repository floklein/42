/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:01:11 by fklein            #+#    #+#             */
/*   Updated: 2015/10/28 20:47:10 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
char	*ft_strstr(char *str, char *tofind)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (tofind[j] == str[i + j])
		{
			if (tofind[j + 1] == '\0')
				return (str + i);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int		main()
{
	char tabc[] = "dadada";
	char tabc2[] = "bababa";

	printf("%s",ft_strstr(tabc, tabc2));
}
