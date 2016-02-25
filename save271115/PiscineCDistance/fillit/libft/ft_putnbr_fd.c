/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:07:14 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/06 00:42:55 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(long nbr, int fd)
{
	if (nbr < 10)
		ft_putchar_fd('0' + nbr, fd);
	else
	{
		ft_print(nbr / 10, fd);
		ft_putchar_fd('0' + nbr % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	ft_print(nbr, fd);
}
