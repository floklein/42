/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:01:11 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 22:39:44 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*(str + i))
	{
		j = i;
		k = 0;
		while (*(str + j) == *(to_find + k))
		{
			j++;
			k++;
			if (*(to_find + k) == '\0')
				return (str + i);
		}
		i++;
	}
	return (NULL);
}

int		main(void)
{
	printf("%s", ft_strstr("salut tu vas bien vas ?", "vas"));
	printf("%s", strstr("salut tu vas bien vas ?", "vas"));
}
