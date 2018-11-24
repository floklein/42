/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:00:00 by flklein           #+#    #+#             */
/*   Updated: 2018/08/29 15:15:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		mult;

	mult = 3;
	if (nb != 2147483647)
		while (nb % mult != 0 && mult <= nb)
			mult += 2;
	return (nb > 0 && nb != 1 && (nb % mult != 0 || mult == nb)
			&& (nb == 2 || nb % 2 != 0) ? 1 : 0);
}

int		ft_find_next_prime(int nb)
{
	while (nb < 2147483647 && !ft_is_prime(nb))
		nb++;
	return (nb);
}
