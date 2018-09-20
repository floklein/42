/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:01:23 by flklein           #+#    #+#             */
/*   Updated: 2018/09/15 23:39:34 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display(int x, int y, int a, int b)
{
	if (b == 1 && a == 1)
		ft_putchar('o');
	else if (b == 1 && a == x)
		ft_putchar('o');
	else if (b == y && a == 1)
		ft_putchar('o');
	else if (b == y && a == x)
		ft_putchar('o');
	else if (b == 1 || b == y)
		ft_putchar('-');
	else if (a == 1 || a == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		a;
	int		b;

	b = 1;
	if (x > 0 && y > 0)
	{
		while (b >= 1 && b <= y)
		{
			a = 1;
			while (a >= 1 && a <= x)
			{
				display(x, y, a, b);
				a++;
			}
			ft_putchar('\n');
			b++;
		}
	}
}
