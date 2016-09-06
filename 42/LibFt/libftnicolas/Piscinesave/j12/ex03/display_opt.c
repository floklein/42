/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:18:48 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:59:00 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_char_opt(char *tab)
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

void	display_space_opt(int *count_valid)
{
	int		count;

	count = count_valid[0];
	if (count < 8)
		ft_putchar(' ');
	while (count < 16)
	{
		ft_putchar(' ');
		ft_putstr("  ");
		count++;
	}
}

void	display_count_opt(int *char_nb)
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

void	display_tab_opt(char *str)
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

void	display_opt(char *str, int *count_valid, int *char_nb)
{
	int		option_nb;

	option_nb = count_valid[2];
	while (option_nb != 0)
	{
		display_count_opt(char_nb);
		ft_putstr("  ");
		display_tab_opt(str);
		display_char_opt(str);
		ft_putchar('\n');
		option_nb--;
	}
	*char_nb = *char_nb + count_valid[0];
}
