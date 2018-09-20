/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:59:10 by flklein           #+#    #+#             */
/*   Updated: 2018/09/05 14:43:19 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			nb++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
	}
	return (nb);
}

int		len_nw(char *str)
{
	int		len;

	len = 0;
	while (str[len]
			&& !(str[len] == ' ' || str[len] == '\t' || str[len] == '\n'))
		len++;
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		pos;
	int		i;
	int		j;

	if (!(tab = (char **)malloc((count_words(str) + 1) * sizeof(char *))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
		{
			if (!(tab[pos] = (char *)malloc(len_nw(str + i) * sizeof(char))))
				return (NULL);
			j = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				tab[pos][j++] = str[i++];
			tab[pos++][j] = '\0';
		}
	}
	tab[pos] = NULL;
	return (tab);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	char	**tab;
	int		p;

	printf("words:%d\n", count_words(av[1]));
	tab = ft_split_whitespaces(av[1]);
	p = 0;
	while (tab[p++])
		printf("tab[%d]:%s\n", p - 1, tab[p - 1]);
	return (ac);
}
