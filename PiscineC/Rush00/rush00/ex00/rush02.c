/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 00:18:14 by flklein           #+#    #+#             */
/*   Updated: 2018/09/15 23:48:25 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display(int x, int y, int a, int b)
{
	if (b == 1 && a == 1)
		ft_putchar('A');
	else if (b == 1 && a == x)
		ft_putchar('A');
	else if (b == y && a == 1)
		ft_putchar('C');
	else if (b == y && a == x)
		ft_putchar('C');
	else if (b == 1 || b == y)
		ft_putchar('B');
	else if (a == 1 || a == x)
		ft_putchar('B');
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
