/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:03:09 by nthibaud          #+#    #+#             */
/*   Updated: 2016/06/29 16:42:42 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char **tab, int i)
{
	char	*tmp_tab;

	tmp_tab = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp_tab;
}

void			ft_sort(char **tab, int *i, int *sort, int *unsort)
{
	if (tab[*i + 1] != '\0')
	{
		while (*sort == 0)
		{
			if (ft_strcmp(tab[*i], tab[*i + 1]) > 0)
			{
				ft_swap(tab, *i);
				*unsort = *unsort + 1;
			}
			if (tab[*i + 2] == '\0' && *unsort == 0)
				*sort = 1;
			if (*sort == 0 && tab[*i + 2] == '\0')
			{
				*i = -1;
				*unsort = 0;
			}
			*i = *i + 1;
		}
	}
}

void			ft_sort_wordtab(char **tab)
{
	int		i;
	int		sort;
	int		unsort;

	i = 0;
	sort = 0;
	unsort = 0;
	ft_sort(tab, &i, &sort, &unsort);
}
