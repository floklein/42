/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:25:33 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/25 15:31:35 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nb_words(char const *str, char c)
{
	int		in_w;
	int		nb_w;
	int		i;

	in_w = 0;
	nb_w = 0;
	i = 0;
	while (str[i])
	{
		if (in_w == 0 && str[i] != c)
			in_w = 1;
		if (in_w == 1 && str[i] == c)
		{
			in_w = 0;
			nb_w++;
		}
		i++;
	}
	return (nb_w + in_w);
}

static void		ft_count_letters(char const *str, int *index,
				int *nbl_pos, char c)
{
	nbl_pos[0] = 0;
	while (str[*index] == c)
		*index += 1;
	while (str[*index] != c && str[*index] != '\0')
	{
		nbl_pos[0]++;
		*index += 1;
	}
	nbl_pos[1] = *index - nbl_pos[0];
}

static char		*ft_stock_letters(char const *str, char **tab, int nb_w, char c)
{
	int		i;
	int		j;
	int		index;
	int		nbl_pos[2];

	i = 0;
	j = 0;
	index = 0;
	nbl_pos[0] = 0;
	nbl_pos[1] = 0;
	while (i < nb_w)
	{
		ft_count_letters(str, &index, nbl_pos, c);
		if ((tab[i] = (char *)malloc(sizeof(char) * (nbl_pos[0] + 1)))
		== NULL)
			return (NULL);
		j = 0;
		while (nbl_pos[1] < index)
			tab[i][j++] = str[nbl_pos[1]++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_w;
	char	**tab;

	if (s == NULL)
		return (NULL);
	nb_w = ft_nb_words(s, c);
	if ((tab = (char **)malloc(sizeof(char*) * (nb_w + 1))) == NULL)
		return (NULL);
	ft_stock_letters(s, tab, nb_w, c);
	return (tab);
}
