/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 23:56:13 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/28 19:47:45 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int count;

	count = nb;
	if (power == 0)
		return (1);
	if (power > 0)
	{
		while (power > 1)
		{
			nb = nb * count;
			power--;
		}
		return (nb);
	}
	else
		return (0);
}
