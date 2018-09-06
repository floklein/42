/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:59:10 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 01:16:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		in_charset(char *charset, char c)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (in_charset(charset, str[i]))
			i++;
		if (str[i])
			nb++;
		while (str[i] && !in_charset(charset, str[i]))
			i++;
	}
	return (nb);
}

int		len_nw(char *str, char *charset)
{
	int		len;

	len = 0;
	while (str[len] && !in_charset(charset, str[len]))
		len++;
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		pos;
	int		i;
	int		j;

	if (!(tab = (char **)malloc((count_words(str, charset) + 1)
					* sizeof(char *))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (in_charset(charset, str[i]))
			i++;
		if (str[i])
		{
			if (!(tab[pos] = (char *)malloc(len_nw(str + i, charset)
							* sizeof(char))))
				return (NULL);
			j = 0;
			while (str[i] && !in_charset(charset, str[i]))
				tab[pos][j++] = str[i++];
			tab[pos++][j] = '\0';
		}
	}
	tab[pos] = NULL;
	return (tab);
}
