/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 17:24:31 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/15 17:28:15 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void				stock_size(char **av, t_stock_param *s_tab, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (av[i][j++] != '\0')
		count++;
	s_tab[i].size_param = count;
}

void				stock_copy(t_stock_param *s_tab, int i)
{
	int	j;

	j = 0;
	s_tab[i].copy = malloc(sizeof(char) * (s_tab[i].size_param + 1));
	while (s_tab[i].str[j] != '\0')
	{
		s_tab[i].copy[j] = s_tab[i].str[j];
		j++;
	}
	s_tab[i].copy[j] = '\0';
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_param	*s_tab;
	int				i;
	int				j;

	i = 0;
	j = 0;
	s_tab = malloc(sizeof(t_stock_param) * (ac + 1));
	while (i < ac)
	{
		stock_size(av, s_tab, i);
		s_tab[i].str = av[i];
		stock_copy(s_tab, i);
		s_tab[i].tab = ft_split_whitespaces(s_tab[i].str);
		i++;
	}
	s_tab[i].str = 0;
	return (s_tab);
}
