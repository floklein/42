/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tab_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 16:05:14 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/19 16:10:34 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_str_tab_dup(char **tab)
{
	int		len;
	int		i;
	char	**tmp;

	len = ft_str_tab_len(tab);
	tmp = malloc(sizeof(*tmp) * (len + 1));
	i = 0;
	while (i < len)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
