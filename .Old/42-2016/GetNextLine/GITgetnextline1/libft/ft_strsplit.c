/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:39 by fklein            #+#    #+#             */
/*   Updated: 2017/03/29 09:03:05 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len_db_tab(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			return (len);
		while (s[i] != c && s[i] != 0)
			i++;
		len++;
	}
	return (len);
}

static char	**ft_solve_split(char **temp, int len1, const char *s, char c)
{
	int				i;
	int				j;
	size_t			len2;
	unsigned int	start;

	i = 0;
	j = 0;
	while (len1)
	{
		len2 = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != 0)
		{
			len2++;
			i++;
		}
		temp[j] = (char *)malloc(sizeof(**temp) * (len2 + 1));
		temp[j] = ft_memcpy(temp[j], s + start, len2);
		temp[j++][len2] = 0;
		len1--;
	}
	temp[j] = NULL;
	return (temp);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**temp;
	int				len1;

	if (s && c)
	{
		len1 = 0;
		len1 = ft_len_db_tab(s, c);
		temp = (char **)malloc(sizeof(*temp) * (len1 + 1));
		if (!temp)
			return (temp);
		temp = ft_solve_split(temp, len1, s, c);
		return (temp);
	}
	return (NULL);
}
