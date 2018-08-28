/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 00:02:14 by flklein           #+#    #+#             */
/*   Updated: 2018/08/28 00:40:15 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		copy;
	int		d;

	d = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -1 * nb;
	}
	copy = nb;
	if (nb == 0)
		ft_putchar('0');
	while (copy >= 10)
	{
		copy = copy / 10;
		d = d * 10;
	}
	while (nb != 0)
	{
		ft_putchar(nb / d + 48);
		nb = nb % d;
		d = d / 10;
	}
}

int		main(void)
{
//	ft_putnbr(123456);
	ft_putnbr(-105);
//	ft_putnbr(2147483647);
//	ft_putnbr(0);
}
