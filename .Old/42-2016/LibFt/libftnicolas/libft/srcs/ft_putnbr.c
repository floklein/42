/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:08:53 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/23 18:18:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n <= -10)
		{
			ft_putchar('-');
			ft_putnbr(-1 * (n / 10));
			ft_putchar('0' + -1 * (n % 10));
		}
		if (n > -10)
		{
			ft_putchar('-');
			ft_putchar('0' - n);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar('0' + n % 10);
		}
		else
			ft_putchar('0' + n);
	}
}
