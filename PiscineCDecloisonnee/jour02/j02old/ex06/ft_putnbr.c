/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 12:11:05 by fklein            #+#    #+#             */
/*   Updated: 2015/10/20 11:27:00 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int long;
	
	long = nb;
	if (long < 0)
	{
		ft_putchar('-');
		ft_putnbr(-long);
	}
	else if (long != 0)
	{
		ft_putnbr(long / 10);
		ft_putchar('0' + long % 10);
	}
}
