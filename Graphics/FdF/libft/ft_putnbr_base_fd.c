/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:13:26 by flklein           #+#    #+#             */
/*   Updated: 2018/11/09 17:14:48 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char const *str)
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

void		ft_putnbr_base_fd(int nbr, char const *base, int fd)
{
	int		base_n;

	base_n = check_base(base);
	if (base_n > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_base_fd(-1 * (nbr / base_n), base, fd);
			ft_putchar_fd(base[-1 * (nbr % base_n)], fd);
		}
		else if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_base_fd(-nbr, base, fd);
		}
		else if (nbr >= base_n)
		{
			ft_putnbr_base_fd(nbr / base_n, base, fd);
			ft_putnbr_base_fd(nbr % base_n, base, fd);
		}
		else
			ft_putchar_fd(base[nbr], fd);
	}
}
