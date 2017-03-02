/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:05:06 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 16:49:32 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n <= -10)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-1 * (n / 10), fd);
			ft_putchar_fd('0' + -1 * (n % 10), fd);
		}
		if (n > -10)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('0' - n, fd);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd('0' + n % 10, fd);
		}
		else
			ft_putchar_fd('0' + n, fd);
	}
}
