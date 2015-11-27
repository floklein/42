/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:59:40 by fklein            #+#    #+#             */
/*   Updated: 2015/10/31 15:57:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int						ft_strlen(char *str)
{
	int				len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char					*ft_strdup(char *src)
{
	int				index;
	char			*cpy;

	index = 0;
	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(src) + 1));
	while (*(src + index))
	{
		*(cpy + index) = *(src + index);
		index++;
	}
	*(cpy + index) = '\0';
	return (cpy);
}

struct s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*box;
	int				index;

	index = 0;
	if ((box = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))) == NULL)
		return (NULL);
	while (index < ac)
	{
		box[index].size_param = ft_strlen(av[index]);
		box[index].str = av[index];
		box[index].copy = ft_strdup(av[index]);
		box[index].tab = ft_split_whitespaces(av[index]);
		index++;
	}
	box[index].str = 0;
	return (box);
}
