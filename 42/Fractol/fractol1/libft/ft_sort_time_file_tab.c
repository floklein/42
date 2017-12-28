/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_time_file_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:06:24 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:06:28 by fklein           ###   ########.fr       */
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
