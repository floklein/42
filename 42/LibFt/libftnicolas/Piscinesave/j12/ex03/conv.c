/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:16:12 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:37:09 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_count_valid_hex(int *count_valid)
{
	count_valid[0] = 0;
	count_valid[1] = 0;
}

void	init_count_valid_opt(int *count_valid, int option_nb)
{
	count_valid[0] = 0;
	count_valid[1] = 0;
	count_valid[2] = option_nb;
}

char	*int_conv(char *tab, int nb)
{
	int		i;
	int		size;

	size = 1;
	i = 10;
	while (i <= nb)
	{
		size++;
		i = i * 10;
	}
	tab = malloc(sizeof(char) * size + 1);
	tab[size] = '\0';
	size--;
	while (nb > 9)
	{
		tab[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	if (nb < 10)
	{
		tab[size] = nb + 48;
	}
	return (tab);
}

char	*int_to_char(char c, char *tab)
{
	int		i;
	int		size;
	int		nb;

	nb = c;
	size = 1;
	i = 10;
	while (i <= nb)
	{
		size++;
		i = i * 10;
	}
	tab[size] = '\0';
	size--;
	while (nb > 9)
	{
		tab[size] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	if (nb < 10)
	{
		tab[size] = nb + 48;
	}
	return (tab);
}

void	tab_cmp(int *count_valid, int *char_nb, int *identical)
{
	*char_nb = *char_nb + count_valid[0];
	if (*identical == 0)
	{
		ft_putstr("*\n");
		*identical = 1;
	}
}
