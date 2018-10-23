/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 17:36:34 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/19 22:12:34 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_num(int a, int b, int c)
{
	a = 48 + a;
	b = 48 + b;
	c = 48 + c;
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;

	a = -1;
	while (a++ < 9)
	{
		b = a;
		while (b++ < 9)
		{
			c = b;
			while (c++ < 9)
			{
				ft_print_num(a, b, c);
				if (!(a == 7 && b == 8 && c == 9))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
