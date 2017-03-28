/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:34:27 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 14:48:29 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
