/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 00:06:41 by flklein           #+#    #+#             */
/*   Updated: 2018/08/29 00:48:03 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int		i;
	int		j;
	int		sorted;

	i = size - 1;
	while (i > 0)
	{
		sorted = 1;
		j = 0;
		while (j < i)
		{
			if (tab[j + 1] < tab[j])
			{
				ft_swap(&tab[j + 1], &tab[j]);
				sorted = 0;
			}
			j++;
		}
		if (sorted)
			break ;
		i--;
	}
}
