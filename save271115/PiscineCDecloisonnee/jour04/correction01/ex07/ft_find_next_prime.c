/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:58:22 by cchaumar          #+#    #+#             */
/*   Updated: 2015/10/23 14:22:30 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_2_pow(int n)
{
	if (n == 0)
		return (1);
	else
		return (2 * ft_2_pow(n - 1));
}

int		ft_is_prime(int nb)
{
	int i;
	int lim;

	i = 1;
	if (nb == 0 || nb == 1 || nb == -2147483648)
		return (0);
	if (nb == 2)
		return (1);
	while (ft_2_pow(2 * i) < nb && i <= 15)
		i++;
	lim = ft_2_pow(i - 1);
	i = 1;
	while (++i <= nb / lim + 1)
		if (nb % i == 0)
			return (0);
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb % 2 == 0)
		nb++;
	while (ft_is_prime(nb) == 0)
		nb += 2;
	return (nb);
}
