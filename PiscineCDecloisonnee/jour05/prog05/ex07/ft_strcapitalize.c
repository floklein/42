/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:44:13 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (*(str + index))
	{
		if (*(str + index) >= 'a' && *(str + index) <= 'z')
			if ((*(str + index - 1) >= 0 && *(str + index - 1) < 48)
					|| (*(str + index - 1) > 57 && *(str + index - 1) < 65)
					|| (*(str + index - 1) > 90 && *(str + index - 1) < 97)
					|| (*(str + index - 1) > 122))
				*(str + index) -= 32;
		index++;
	}
	return (str);
}

int		main(void)
{
	char tab[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s", ft_strcapitalize(tab));
	return (0);
}
