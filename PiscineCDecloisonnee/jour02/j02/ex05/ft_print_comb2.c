/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:07:40 by fklein            #+#    #+#             */
/*   Updated: 2015/10/20 23:45:47 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_putchar(char c);

void	ft_putnbr(int c)
{
	if (c < 10)
		ft_putchar(c + '0');
	if (c >= 10)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
}

void	ft_print(int a, int b)
{
	if (a > b)
	{
		if (b < 10)
			ft_putchar('0');
		ft_putnbr(b);
		ft_putchar(' ');
		if (a < 10)
			ft_putchar('0');
		ft_putnbr(a);
		if (a != 99 || b != 98)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	b = 00;
	while (a <= 99)
	{
		ft_print(a, b);
		if (b < 98 && a == 99)
		{
			a = 00;
			b++;
		}
		a++;
	}
}
