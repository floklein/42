/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:18:12 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:38:57 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_char_inopt(char *tab)
{
	int		i;

	i = 0;
	ft_putstr("  ");
	ft_putchar('|');
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n' || tab[i] == '\t')
			ft_putchar('.');
		else
			ft_putchar(tab[i]);
		i++;
	}
	ft_putchar('|');
}

void	display_count_inopt(int *char_nb)
{
	char	*tab;
	int		len;

	tab = NULL;
	tab = int_conv(tab, *char_nb);
	len = ft_strlen(ft_convert_base(tab, "0123456789", "0123456789abcdef"));
	len = 8 - len;
	while (len-- != 0)
		ft_putchar('0');
	ft_putstr(ft_convert_base(tab, "0123456789", "0123456789abcdef"));
	free(tab);
}

void	display_tab_inopt(char *str)
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
		if (i == 8)
			ft_putchar(' ');
	}
}

void	display_inopt(char *str, int *count_valid, int *char_nb)
{
	int		option_nb;

	option_nb = count_valid[2];
	while (option_nb != 0)
	{
		display_count_inopt(char_nb);
		ft_putstr("  ");
		display_tab_inopt(str);
		display_char_inopt(str);
		ft_putchar('\n');
		option_nb--;
	}
	*char_nb = *char_nb + count_valid[0];
}
