/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 09:44:48 by fklein            #+#    #+#             */
/*   Updated: 2015/10/18 14:25:25 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	test(int l, int h, int x, int y)
{
	if (l == 1 && h == 1)
		ft_putchar('/');
	else if (l == x && h == 1)
		ft_putchar('\\');
	else if (l == 1 && h == y)
		ft_putchar('\\');
	else if (l == x && h == y)
		ft_putchar('/');
	else if (h == 1 || h == y)
		ft_putchar('*');
	else if (l == 1 || l == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	colle(x, y)
{
	int lc;
	int hc;

	lc = 1;
	hc = 1;
	while (hc <= y)
	{
		while (lc <= x)
		{
			test(lc, hc, x, y);
			lc++;
		}
		ft_putchar('\n');
		lc = 1;
		hc++;
	}
}