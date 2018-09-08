/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:39:28 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 11:46:18 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, int length)
{
	int		i;
	int		max;

	if (length == 0)
		return (0);
	max = -2147483648;
	i = 0;
	while (i < length)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int		main()
{
	int		tab[7] = {1, 2, -3, 4, -5, 17, -20};

	printf("%d\n", ft_max(tab, 7));
}
