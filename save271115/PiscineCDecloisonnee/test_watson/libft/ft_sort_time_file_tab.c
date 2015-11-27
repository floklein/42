/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time_file_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 11:37:04 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/11 09:51:03 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

char	**ft_sort_time_file_tab(char **tab, int len)
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
			if (1)
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
