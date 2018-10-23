/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 20:52:59 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/27 19:14:56 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 0 && nb <= 12)
	{
		if (nb >= 2)
		{
			nb = nb * ft_recursive_factorial(nb - 1);
		}
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}
