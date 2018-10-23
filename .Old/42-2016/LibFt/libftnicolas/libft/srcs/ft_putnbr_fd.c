/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:22:34 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/23 18:29:13 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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
