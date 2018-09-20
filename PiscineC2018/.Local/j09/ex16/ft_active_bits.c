/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:10:51 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 11:33:44 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 || power == 1)
		return (power ? nb : 1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

unsigned int	ft_active_bits(int value)
{
	unsigned int	count;

	count = 0;
	if (value >= 0)
	{
		while (value > 0)
		{
			if ((value & 1) == 1)
				count++;
			value >>= 1;
		}
		return (count);
	}
	else
	{
		value = ft_recursive_power(2, 32) - value;
		while (value > 0)
		{
			if ((value & 1) == 1)
				count++;
			value >>= 1;
		}
		return (count);
	}
}

int		main(int ac, char **av)
{
	printf("%d\n", ft_active_bits(atoi(av[1])));
}
