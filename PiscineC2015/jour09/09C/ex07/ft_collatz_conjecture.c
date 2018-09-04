/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 00:25:24 by fklein            #+#    #+#             */
/*   Updated: 2015/10/23 00:49:29 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz(unsigned int base, unsigned int index)
{
	if (base == 1)
		return (index);
	index++;
	if (base % 2 == 0)
		return (ft_collatz(base / 2, index++));
	else
		return (ft_collatz(3 * base + 1, index++));
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	unsigned int index;

	index = 0;
	return (ft_collatz(base, index));
}
