/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:11:24 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 14:31:44 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		in_base(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		base_n;
	int		nb;
	int		sign;
	int		i;

	base_n = check_base(base);
	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		sign *= (str[i++] == '-' ? -1 : 1);
	while (in_base(base, str[i]) != -1)
	{
		nb = nb * base_n + in_base(base, str[i]);
		i++;
	}
	if (!str[i] || str[i] == '-' || str[i] == '+')
		return (sign * nb);
	else
		return (0);
}

void	ft_strnbr_base(long nbr, char *base, char **nb_to, int i)
{
	long	base_n;

	base_n = check_base(base);
	if (base_n > 1)
	{
		if (nbr < 0)
		{
			nb_to[0][0] = '-';
			ft_strnbr_base(-nbr, base, nb_to, 1);
		}
		else if (nbr >= base_n)
		{
			ft_strnbr_base(nbr / base_n, base, nb_to, i + 1);
			ft_strnbr_base(nbr % base_n, base, nb_to, i);
		}
		else
			nb_to[0][i] = base[nbr];
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb_10;
	char	*nb_to;
	char	tmp;
	int		i;
	int		len;

	nb_10 = ft_atoi_base(nbr, base_from);
	if (!(nb_to = (char *)malloc(100 * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < 100)
		nb_to[i++] = 0;
	ft_strnbr_base(nb_10, base_to, &nb_to, 0);
	i = 0;
	nb_to += (nb_to[i] == '-' ? 1 : 0);
	len = 0;
	while (nb_to[len])
		len++;
	while (i < len / 2)
	{
		tmp = nb_to[i];
		nb_to[i] = nb_to[len - i - 1];
		nb_to[len - i++ - 1] = tmp;
	}
	return (nb_to[-1] == '-' ? nb_to - 1 : nb_to);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	printf("res:%s", ft_convert_base(av[1], av[2], av[3]));
	return (ac);
}
