/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 02:56:14 by flklein           #+#    #+#             */
/*   Updated: 2018/09/03 14:54:16 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		check_base(char *str)
{
	int		len;
	int		i;

	len = 0;
	while (str[len])
	{
		if (str[len] == '+' || str[len] == '-')
			return (0);
		i = len;
		while (i-- >= 0)
			if (str[i] == str[len])
				return (0);
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_n;

	base_n = check_base(base);
	if (base_n > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putnbr_base(-1 * (nbr / base_n), base);
			ft_putchar(base[-1 * (nbr % base_n)]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base(-nbr, base);
		}
		else if (nbr >= base_n)
		{
			ft_putnbr_base(nbr / base_n, base);
			ft_putnbr_base(nbr % base_n, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
