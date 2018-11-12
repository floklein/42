/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:14:51 by flklein           #+#    #+#             */
/*   Updated: 2018/11/09 18:34:18 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ct_wrd(char const *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			nb++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nb);
}

static int	len_nw(char const *str, char c)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		pos;
	int		i;
	int		j;

	if (!str || !(tab = (char **)malloc((ct_wrd(str, c) + 1) * sizeof(char *))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			if (!(tab[pos] = (char *)malloc(len_nw(str + i, c) * sizeof(char))))
				return (NULL);
			j = 0;
			while (str[i] && str[i] != c)
				tab[pos][j++] = str[i++];
			tab[pos++][j] = '\0';
		}
	}
	tab[pos] = NULL;
	return (tab);
}
