/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:44:44 by nsavry            #+#    #+#             */
/*   Updated: 2014/02/23 22:51:05 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		nb;

	nb = 0;
	nb = ft_str_tab_len(tab);
	tab = ft_realloc_str_tab(tab, nb, nb);
	return (tab);
}
