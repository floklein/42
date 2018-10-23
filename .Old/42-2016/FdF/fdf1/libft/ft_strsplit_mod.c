/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/29 09:05:05 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len_db_tab(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return ((s[i - 1] == c) ? len : len + 1);
}

static char		**ft_solve_split(char **tab, int len_tab, const char *s, char c)
{
	int		i;
	int		ind_tab;
	int		len_next;
	int		j;

	i = 0;
	ind_tab = 0;
	while (ind_tab < len_tab + 2)
	{
		len_next = 0;
		while (s[i + len_next] && s[i + len_next] != c)
			len_next++;
		tab[ind_tab] = (char *)malloc(sizeof(**tab) * (len_next + 1));
		j = 0;
		while (s[i] && s[i] != c)
		{
			tab[ind_tab][j] = s[i];
			i++;
			j++;
		}
		tab[ind_tab][j] = '\0';
		ind_tab++;
		i++;
	}
	return (tab);
}

char			**ft_strsplit_mod(char const *str, char c)
{
	char	**tab;
	int		len_tab;

	if (str && c)
	{
		len_tab = ft_len_db_tab(str, c);
		if (!(tab = (char **)malloc(sizeof(char *) * (len_tab + 2))))
			return (NULL);
		tab = ft_solve_split(tab, len_tab, str, c);
		tab[len_tab + 1] = 0;
		return (tab);
	}
	return (NULL);
}
