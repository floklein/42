/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:31:20 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 22:34:58 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
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
