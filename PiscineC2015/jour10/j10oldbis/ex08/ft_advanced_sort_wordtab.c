/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:51:50 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 23:06:46 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		count;
	int		n;

	i = 0;
	count = 0;
	n = 0;
	while (tab[n])
		n++;
	while (count < n)
	{
		while (i < n - count - 1)
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		i = 0;
		count++;
	}
}
