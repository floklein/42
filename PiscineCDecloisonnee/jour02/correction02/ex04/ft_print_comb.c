/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 19:01:29 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 15:04:59 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_print_comb(int n);
int	main()
{
	int		a;
	int		b;
	int		c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		a++;
		while (b <= 8)
		{
			c = b + 1;
			b++;
			while (c <= 9)
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				c++;
			}
		}
	}
}
