/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:47:03 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 01:16:09 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	ft_print_words_tables(char **tab)
{
	int		p;

	p = 0;
	while (tab[p])
	{
		ft_putstr(tab[p]);
		ft_putchar('\n');
		p++;
	}
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_split(char *str, char *charset);

int		main(int ac, char **av)
{
	ft_print_words_tables(ft_split(av[1], av[2]));
	return (ac);
}
