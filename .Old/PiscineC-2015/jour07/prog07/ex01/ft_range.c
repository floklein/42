/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:50:14 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 19:04:33 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		*ft_range(int min, int max)
{
	int		*tab;
	int		index;

	index = 0;
	if (min >= max)
		return (tab = NULL);
	else
	{
		tab = malloc(sizeof(int) * (max - min));
		while (index < max - 1)
		{
			*(tab + index) = min + index;
			printf("%d", min + index); // AAAAAAAA REEETTIIIIIIRREEEEEEERRRRR !!!
			index++;
		}
	}
	return (tab);
}

int		main(void)
{
	ft_range(10, 20);
}