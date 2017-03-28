/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 15:56:35 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 15:37:18 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putchar_all(char ad, char bd, char cd, char cod, char sd)
{
	ft_putchar(ad);
	ft_putchar(bd);
	ft_putchar(cd);
	if (ad != 55 || bd != 56 || cd != 57)
	{
		ft_putchar(cod);
		ft_putchar(sd);
	}
}

void    ft_print_comb(void)
{
    char	a;
	char	b;
	char	c;
	
	a = 48;
    while (a <= 55)
    {
        b = a + 1;
        while (b <= 56)
        {
            c = b + 1;
            while (c <= 57)
            {
				ft_putchar_all(a, b, c, ',', ' ');
				c++;
			}
        	b++;
		}
    	a++;
	}
}
