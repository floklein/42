/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:23:31 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 21:02:32 by flklein          ###   ########.fr       */
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

int			*ft_intsplitstr(char const *str, char const *set)
{
	int		*tab;
	int		pos;
	int		i;

	if (!(tab = (int *)malloc(count(str, set) * sizeof(int))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (in_set(set, str[i]))
			i++;
		if (str[i])
		{
			tab[pos++] = ft_atoi(str + i);
			while (str[i] && !in_set(set, str[i]))
				i++;
		}
	}
	return (tab);
}
