/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 17:07:21 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/21 14:44:21 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = -1;
	b = 0;
	while (a++ < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_putchar('0' + a / 10);
			ft_putchar('0' + a % 10);
			ft_putchar(' ');
			ft_putchar('0' + b / 10);
			ft_putchar('0' + b % 10);
			if (a != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
	}
}
