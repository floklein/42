/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 18:31:15 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/21 14:30:19 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char n);

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb <= -10)
		{
			ft_putchar('-');
			ft_putnbr(-1 * (nb / 10));
			ft_putchar('0' + -1 * (nb % 10));
		}
		if (nb > -10)
		{
			ft_putchar('-');
			ft_putchar('0' - nb);
		}
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar('0' + nb % 10);
		}
		else
			ft_putchar('0' + nb);
	}
}
