/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 02:56:14 by flklein           #+#    #+#             */
/*   Updated: 2018/09/02 03:52:02 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '+' || str[len] == '-')
			return (0);
		len++;
	}
	return (len);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		base_n;

	base_n = check_base(base);
	if (base_n > 1)
	{
		if (nb == -2147483648)
		{}
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= base_n)
		{
			ft_putnbr_base(nb / base_n, base);
			ft_putnbr_base(nb % base_n, base);
		}
		else
			ft_putchar(base[nb]);
	}
}

int		main()
{
	ft_putnbr_base(-12345, "01234567");
}
