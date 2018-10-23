/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 17:14:42 by fklein            #+#    #+#             */
/*   Updated: 2015/10/29 20:39:16 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_split_whitespaces(char *str);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	ft_print_words_tables(char **tab)
{
	int		index;

	index = 0;
	while (tab[index])
	{
		ft_putstr(tab[index]);
		ft_putchar('\n');
		index++;
	}
}

int		main(void)
{
	char test[] = "4W                Zlf8sgu                 lYohPnspt               fSWYNkaQ9Xi";

	ft_print_words_tables(ft_split_whitespaces(test));
}
