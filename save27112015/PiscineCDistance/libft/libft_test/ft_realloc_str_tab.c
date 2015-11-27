/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 17:56:05 by nsavry            #+#    #+#             */
/*   Updated: 2014/01/22 17:59:21 by nsavry           ###   ########.fr       */
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
