/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:16:46 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:08:42 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_space_hex(int *count_valid)
{
	int		count;

	count = count_valid[0];
	while (count < 16)
	{
		ft_putstr("  ");
		count++;
		if (count <= 16)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	display_count_hex(int *char_nb, int *count_valid)
{
	char	*tab;
	int		len;

	tab = NULL;
	tab = int_conv(tab, *char_nb);
	len = ft_strlen(ft_convert_base(tab, "0123456789", "0123456789abcdef"));
	len = 7 - len;
	while (len-- != 0)
		ft_putchar('0');
	ft_putstr(ft_convert_base(tab, "0123456789", "0123456789abcdef"));
	if (count_valid[1] != 0)
		ft_putchar(' ');
	free(tab);
}

void	display_tab_hex(char *str)
{
	int		i;
	char	tab[4];

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strlen(ft_convert_base(int_to_char(str[i], tab)
		, "0123456789", "0123456789abcdef")) == 1)
			ft_putchar('0');
		ft_putstr(ft_convert_base(int_to_char(str[i], tab)
		, "0123456789", "0123456789abcdef"));
		i++;
		if (str[i] != '\0')
			ft_putchar(' ');
	}
}

void	display_hex(char *str, int *count_valid, int *char_nb)
{
	display_count_hex(char_nb, count_valid);
	*char_nb = *char_nb + count_valid[0];
	display_tab_hex(str);
	ft_putchar('\n');
}
