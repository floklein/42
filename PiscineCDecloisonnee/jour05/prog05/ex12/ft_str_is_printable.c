/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 07:52:54 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 14:46:21 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (33 <= str[i] && str[i] <= 126)
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int		main(void)
{
	char tab[] = "iiiiiikubuyvuy uy\n";

	printf("%d", ft_str_is_printable(tab));
	return (0);
}
