/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:34:27 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 18:56:38 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_strjoin(char *dest, char *src)
{
	int	i;
	
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	char *o;

	o = s;
	while (*(s++))
		;
	return (s - o);
}

void	ft_putstr(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnstr(int fd, char *s, int n)
{
	write(fd, s, n);
}
