/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 00:03:18 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 00:12:52 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1 || base == 0)
		return (0);
	if (base % 2 == 0)
		return (1 + ft_collatz_conjecture(base / 2));
	else
		return (1 + ft_collatz_conjecture(3 * base + 1));
}

int		main(int ac, char **av)
{
	printf("%d\n", ft_collatz_conjecture(atoi(av[1])));
}
