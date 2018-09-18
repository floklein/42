/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:03:32 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 14:37:50 by flklein          ###   ########.fr       */
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

	if (!(len_par = get_params(par, map)))
		return (0);
	par->map = map + len_par + 1;
	ft_putstr(par->map);
	return (1);
}

int		parse_map(t_params *par, char *map)
{
	if (!is_valid(par, map))
		return (0);
	return (1);
}
