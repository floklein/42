/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 23:06:54 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:53:59 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int result;
	int count;

	count = 2;
	result = 0;
	if (nb == 1)
		return (1);
	if (nb <= 12 && nb > 0)
	{
		result = nb * (nb - 1);
		while (count != nb)
		{
			result = result * (nb - count);
			count++;
		}
		return (result);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
