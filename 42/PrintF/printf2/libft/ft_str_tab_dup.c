/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tab_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:06:32 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:06:34 by fklein           ###   ########.fr       */
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
