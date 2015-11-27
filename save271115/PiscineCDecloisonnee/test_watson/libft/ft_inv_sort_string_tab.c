/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inv_sort_string_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 11:37:04 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/15 19:58:27 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_inv_sort_string_tab(char **tab, int len)
{
	int		n;
	char	*temp;
	int		i;

	n = 1;
	while (n != 0)
	{
		n = 0;
		i = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) < 0)
			{
				temp = ft_strdup(tab[i]);
				tab[i] = ft_strdup(tab[i + 1]);
				tab[i + 1] = ft_strdup(temp);
				n++;
			}
			i++;
		}
	}
	return (tab);
}
