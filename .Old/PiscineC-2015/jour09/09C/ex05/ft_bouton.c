/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 22:04:25 by fklein            #+#    #+#             */
/*   Updated: 2015/10/22 22:33:17 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_bouton(int i, int j, int k)
{
	if ((i > j) && (i > k))
	{
		if (j < k)
			return (k);
		else
			return (j);
	}
	else if ((j > i) && (j > k))
	{
		if (i < k)
			return (k);
		else
			return (i);
	}
	else
	{
		if (i < j)
			return (j);
		else
			return (i);
	}
}
