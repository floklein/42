/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 13:53:33 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 20:33:01 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int		length(char *str)
{
	int len;

	len = 0;
	while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int		nb_words(char *str)
{
	int inword;
	int count;
	int index;

	inword = 0;
	count = 0;
	index = 0;
	while (str[index])
	{
		if (inword == 0 && str[index] != ' ' && str[index] != '\t'
				&& str[index] != '\n')
			inword = 1;
		if (inword == 1 && (str[index] == ' ' || str[index] == '\t'
					|| str[index] == '\n'))
		{
			inword = 0;
			count++;
		}
		index++;
	}
	return (count + inword);
}

char	*get_next_word(char *str, char **index_str)
{
	int		index;
	int		len;
	char	*tab;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
		str++;
	len = length(str) + 1;
	tab = malloc(sizeof(char) * len);
	index = -1;
	while (++index < len - 1)
		tab[index] = *(str++);
	tab[index] = '\0';
	*index_str = str;
	return(tab);
}

char	**ft_split_whitespaces(char *str)
{
	int index;
	int	nword;
	char **global;

	if (str == NULL)
		return (NULL);
	nword = nb_words(str) + 1;
	if (nword == 0)
		return (NULL);
	if ((global = malloc(sizeof(char *) * nword)) == NULL)
		return (NULL);
	index = 0;
	while (index < nword - 1)
	{
		global[index] = get_next_word(str, &str);
		index++;
	}
	global[nword - 1] = NULL;
	return (global);
}
