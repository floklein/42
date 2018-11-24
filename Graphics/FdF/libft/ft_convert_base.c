/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:53:37 by flklein           #+#    #+#             */
/*   Updated: 2018/11/09 18:07:45 by flklein          ###   ########.fr       */
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

static int	in_base(char const *str, char c)
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

static int	ft_atoi_base(char const *str, char const *base)
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

static void	ft_itoa_base(long nbr, char const *base, char **nb_to, int i)
{
	long	base_n;

	base_n = check_base(base);
	if (base_n > 1)
	{
		if (nbr < 0)
		{
			nb_to[0][0] = '-';
			ft_itoa_base(-nbr, base, nb_to, 1);
		}
		else if (nbr >= base_n)
		{
			ft_itoa_base(nbr / base_n, base, nb_to, i + 1);
			ft_itoa_base(nbr % base_n, base, nb_to, i);
		}
		else
			nb_to[0][i] = base[nbr];
	}
}

char		*ft_convert_base(char const *nbr, char const *base_from,
		char const *base_to)
{
	long	nb_10;
	char	*nb_to;
	int		len;
	int		i;

	nb_10 = ft_atoi_base(nbr, base_from);
	if (!(nb_to = (char *)malloc(100 * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < 100)
		nb_to[i++] = 0;
	ft_itoa_base(nb_10, base_to, &nb_to, 0);
	i = 0;
	nb_to += (nb_to[i] == '-' ? 1 : 0);
	len = 0;
	while (nb_to[len])
		len++;
	nb_to = ft_strrev(nb_to);
	return (nb_to[-1] == '-' ? nb_to - 1 : nb_to);
}
