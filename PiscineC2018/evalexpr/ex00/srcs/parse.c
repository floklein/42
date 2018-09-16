/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:11:04 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 20:43:17 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

char	*kill_spaces(char *src)
{
	char	*dest;
	int		i;
	int		j;

	if (!(dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ')
			dest[j++] = src[i++];
		else
			i++;
	}
	dest[j] = '\0';
	return (dest);
}

int		is_operand(char ope)
{
	return (ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '%');
}

char	**parse_str(char *src)
{
	char	*str;
	char	**tab;
	int		i;
	int		k;
	int		j;

	str = kill_spaces(src);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!(tab[k] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (NULL);
		j = 0;
		if (str[i] == '(' || str[i] == ')')
			tab[k++][0] = str[i++];
		else if (is_operand(str[i]) && !is_operand(str[i - 1])
					&& str[i - 1] != '(')
			tab[k++][0] = str[i++];
		else
		{
			if (is_operand(str[i]))
				tab[k][j++] = str[i++];
			while (str[i] >= '0' && str[i] <= '9')
				tab[k][j++] = str[i++];
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
