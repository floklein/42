/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:31:20 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 22:33:24 by flklein          ###   ########.fr       */
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

int		main(int ac, char** av)
{
	printf("%d\n", ft_antidote(atoi(av[1]), atoi(av[2]), atoi(av[3])));
}
