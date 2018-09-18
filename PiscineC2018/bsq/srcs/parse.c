/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:03:32 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 16:13:17 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

int		get_params(t_params *par, char *map)
{
	int			i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	par->p = map[i - 3];
	map[i - 3] = '\0';
	par->o = map[i - 2];
	map[i - 2] = '\0';
	par->x = map[i - 1];
	map[i - 1] = '\0';
	if (par->p == par->o || par->p == par->x
			|| par->o == par->x)
		return (0);
	if (!is_numeric(map))
		return (0);
	par->lines = ft_atoi(map);
	if (par->lines < 1)
		return (0);
	printf("lines:%d - emp:%c - obs:%c - full:%c\n",
			par->lines, par->p, par->o, par->x);
	return (i);
}

int		is_valid(t_params *par, char *map)
{
	int		len_par;
	int		length;
	int		i;

	if (!(len_par = get_params(par, map)))
		return (0);
	par->map = map + len_par + 1;
	par->columns = ft_strlen_nl(par->map);
	length = 0;
	i = 0;
	while (par->map[i])
	{
		if (par->map[i] != par->p && par->map[i] != par->o
				&& par->map[i] != par->x && par->map[i] != '\n')
			return (0);
		if (par->map[i] == '\n')
		{
			if (par->map[i + 1] && ft_strlen_nl(par->map + i + 1) != par->columns)
				return (0);
			length++;
		}
		i++;
	}
	return (length == par->lines);
}

int		parse_map(t_params *par, char *map)
{
	if (!is_valid(par, map))
		return (0);
	ft_putstr(par->map);
	printf("width:%d\n", par->columns);
	return (1);
}
