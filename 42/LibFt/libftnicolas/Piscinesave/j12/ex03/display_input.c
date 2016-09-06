/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:17:38 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:26:01 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_count_input(int *char_nb)
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
	ft_putchar(' ');
	free(tab);
}

void	display_tab_input(char *str)
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

void	display_input(char *str, int *count_valid, int *char_nb)
{
	display_count_input(char_nb);
	*char_nb = *char_nb + count_valid[0];
	display_tab_input(str);
	ft_putchar('\n');
}
