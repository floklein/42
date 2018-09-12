/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:54:55 by flklein           #+#    #+#             */
/*   Updated: 2018/09/12 17:17:53 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int				c;
	int				n1;
	int				n2;

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

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_size(char **tab)
{
	int		size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		ct;
	int		size;

	size = ft_size(tab);
	printf("size:%d\n", size);
	i = 0;
	ct = 1;
	while (ct < size)
	{
		while (++i < size - ct)
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
		i = 0;
		ct++;
	}
}

char	**ft_split_whitespaces(char *str);
void	ft_print_words_tables(char **tab);

int		main(int ac, char **av)
{
	char	**tab;

	tab = ft_split_whitespaces(av[1]);
	ft_advanced_sort_wordtab(tab, &ft_strcmp);
	ft_print_words_tables(tab);
}
