/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:46:35 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/11 10:46:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nb_words(char *str)
{
	int in_w;
	int nb_w;
	int i;

	in_w = 0;
	nb_w = 0;
	i = 0;
	while (str[i])
	{
		if (in_w == 0 && str[i] != ' ' && str[i] != '\t'
					&& str[i] != '\n')
			in_w = 1;
		if (in_w == 1 && (str[i] == ' ' || str[i] == '\t'
					|| str[i] == '\n'))
		{
			in_w = 0;
			nb_w++;
		}
		i++;
	}
	return (nb_w + in_w);
}

void	ft_count_letters(char *str, int *index, int *nb_l, int *pos)
{
	*nb_l = 0;
	while (str[*index] == ' ' || str[*index] == '\t' || str[*index] == '\n')
		*index += 1;
	while (str[*index] != ' ' && str[*index] != '\t' && str[*index] != '\n' &&
		str[*index] != '\0')
	{
		*nb_l += 1;
		*index += 1;
	}
	*pos = *index - *nb_l;
}

char	*ft_stock_letters(char *str, char **tab, int nb_w)
{
	int i;
	int j;
	int nb_l;
	int pos;
	int index;

	i = 0;
	j = 0;
	index = 0;
	while (i < nb_w)
	{
		ft_count_letters(str, &index, &nb_l, &pos);
		if ((tab[i] = malloc(sizeof(char) * (nb_l + 1))) == NULL)
			return (NULL);
		j = 0;
		while (pos < index)
			tab[i][j++] = str[pos++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (0);
}

char	**ft_split_whitespaces(char *str)
{
	int		nb_w;
	char	**tab;

	nb_w = ft_nb_words(str);
	if ((tab = malloc(sizeof(char*) * (nb_w + 1))) == NULL)
		return (NULL);
	ft_stock_letters(str, tab, nb_w);
	return (tab);
}
