/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:23:18 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/19 15:13:36 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, int i)
{
	char	*tmp_tab;

	tmp_tab = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp_tab;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		sort;
	int		unsort;

	i = 0;
	sort = 0;
	if (tab[i + 1] != '\0')
	{
		while (sort == 0)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(tab, i);
				unsort++;
			}
			if (tab[i + 2] == '\0' && unsort == 0)
				sort = 1;
			if (sort == 0 && tab[i + 2] == '\0')
			{
				i = -1;
				unsort = 0;
			}
			i++;
		}
	}
}
