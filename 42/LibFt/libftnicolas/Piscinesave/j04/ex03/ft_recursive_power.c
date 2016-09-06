/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 00:32:43 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/27 19:22:03 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power > 0)
	{
		if (power >= 1)
		{
			nb = nb * ft_recursive_power(nb, power - 1);
		}
		return (nb);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}
