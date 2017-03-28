/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 12:12:09 by fklein            #+#    #+#             */
/*   Updated: 2015/10/24 18:05:44 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int val;

	i = 0;
	val = nb;
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb == 0)
		return (1);
	while (nb-- > 1)
		val = val * nb;
	return (val);
}
