/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:22:06 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:21:34 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	read_and_stock_input(char *tab, int *count_valid, int *char_nb)
{
	char	buf[2];
	char	prev_tab[17];
	int		identical;

	identical = 0;
	while (read(0, buf, 1))
	{
		tab[count_valid[0]] = buf[0];
		count_valid[0]++;
		if (count_valid[0] == 16)
		{
			tab[16] = '\0';
			prev_tab[16] = '\0';
			if (ft_strcmp(tab, prev_tab) == 0)
				tab_cmp(count_valid, char_nb, &identical);
			else
			{
				identical = 0;
				display_input(tab, count_valid, char_nb);
			}
			ft_strcpy(tab, prev_tab);
			count_valid[0] = 0;
		}
	}
}

int		ft_hexdump_input(void)
{
	int		char_nb;
	int		count_valid[2];
	char	tab[17];

	char_nb = 0;
	init_count_valid_hex(count_valid);
	read_and_stock_input(tab, count_valid, &char_nb);
	return (0);
}
