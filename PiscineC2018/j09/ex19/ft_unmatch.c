/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:54:38 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 13:06:18 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;
	int		friends;

	i = 0;
	while (i < length)
	{
		j = 0;
		friends = 0;
		while (j < length)
		{
			if (tab[i] == tab[j])
				friends++;
			j++;
		}
		printf("%d has %d friends\n", tab[i], friends);
		if (friends % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}

int		main(void)
{
	int		tab[9] = {1, 1, 2, 4, 3, 4, 2, 3, 4};

	printf("%d\n", ft_unmatch(tab, 9));
}
