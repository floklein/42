/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:05:26 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:05:28 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_realloc_str_tab(char **tab, int old_len, int new_len)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (new_len + 1));
	if (new_len > old_len)
	{
		while (i < old_len)
		{
			new_tab[i] = ft_strdup(tab[i]);
			i++;
		}
		while (i <= new_len)
			new_tab[i++] = NULL;
	}
	else
	{
		while (i < new_len)
		{
			new_tab[i] = ft_strdup(tab[i]);
			i++;
		}
		new_tab[i] = NULL;
	}
	return (new_tab);
}
