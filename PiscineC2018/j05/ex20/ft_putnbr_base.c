/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 02:56:14 by flklein           #+#    #+#             */
/*   Updated: 2018/09/02 03:13:06 by flklein          ###   ########.fr       */
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
	while (str[len++]);
	return (len - 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		base_n;

	base_n = ft_strlen(base);
//	printf("base:%d\n", base_n);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
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

int		main()
{
	ft_putnbr_base(12345, "01234567");
}
