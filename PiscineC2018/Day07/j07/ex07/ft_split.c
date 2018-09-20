/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:59:10 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 14:46:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		in_set(char *set, char c)
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

int		count(char *str, char *set)
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

int		lnw(char *str, char *set)
{
	int		len;

	len = 0;
	while (str[len] && !in_set(set, str[len]))
		len++;
	return (len);
}

char	**ft_split(char *str, char *set)
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
