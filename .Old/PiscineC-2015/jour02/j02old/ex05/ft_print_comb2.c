/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:07:40 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 15:38:18 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_display(char a1d, char b1d, char a2d, char b2d)
{
	if ((a2d > a1d) || (a2d == a1d && b2d > b1d))
	{
		ft_putchar(a1d);
		ft_putchar(b1d);
		ft_putchar(' ');
		ft_putchar(a2d);
		ft_putchar(b2d);
		if (a1d != 57 || b1d != 56 || a2d != 57 || b2d != 57)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_condition(char a1c, char b1c, char a2c, char b2c)
{
	while (a1c <= 57)
	{
		while (b1c <= 56)
		{
			while (a2c <= 57)
			{
				while (b2c <= 57)
				{
					ft_display(a1c, b1c, a2c, b2c);
					b2c++;
				}
				a2c++;
				b2c = 48;
			}
			b1c++;
			a2c = 48;
		}
		a1c++;
		b1c = 48;
	}
}

void	ft_print_comb2(void)
{
	char	a1;
	char	b1;
	char	a2;
	char	b2;

	a1 = 48;
	b1 = 48;
	a2 = 48;
	b2 = 49;
	ft_condition(a1, b1, a2, b2);
}
