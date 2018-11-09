/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:16:01 by flklein           #+#    #+#             */
/*   Updated: 2018/11/09 18:07:11 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count(char const *str, char const *set)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (in_set(set, str[i]))
			i++;
		if (str[i])
			nb++;
		while (str[i] && !in_set(set, str[i]))
			i++;
	}
	return (nb);
}

static int	lnw(char const *str, char const *set)
{
	int		len;

	len = 0;
	while (str[len] && !in_set(set, str[len]))
		len++;
	return (len);
}

char		**ft_strsplitstr(char const *str, char const *set)
{
	char	**tab;
	int		pos;
	int		i;
	int		j;

	if (!(tab = (char **)malloc((count(str, set) + 1) * sizeof(char *))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (in_set(set, str[i]))
			i++;
		if (str[i])
		{
			if (!(tab[pos] = (char *)malloc(lnw(str + i, set) * sizeof(char))))
				return (NULL);
			j = 0;
			while (str[i] && !in_set(set, str[i]))
				tab[pos][j++] = str[i++];
			tab[pos++][j] = '\0';
		}
	}
	tab[pos] = NULL;
	return (tab);
}
