/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:21:58 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/19 15:12:02 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab, int i)
{
	char	*tmp_tab;

	tmp_tab = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp_tab;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		c;
	int		n1;
	int		n2;

	c = 0;
	while (s1[c] != '\0' || s2[c] != '\0')
	{
		if (s1[c] != s2[c])
		{
			n1 = s1[c];
			n2 = s2[c];
			if (n1 > n2 || n1 < n2)
				return (n1 - n2);
		}
		if (s1[c] == s2[c])
			c++;
	}
	return (0);
}

void	ft_sort_wordtab(char **tab)
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
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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
