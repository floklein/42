/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:54:38 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 13:07:48 by flklein          ###   ########.fr       */
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
		if (friends % 2 == 1)
			return (tab[i]);
		i++;
	}
	return (0);
}
