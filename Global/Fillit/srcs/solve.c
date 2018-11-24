/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:23:30 by flklein           #+#    #+#             */
/*   Updated: 2018/11/24 12:05:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_resting_pieces(t_tetri *tetri)
{
	return (!(tetri->placed)
			+ (tetri->next ? ft_resting_pieces(tetri->next) : 0));
}

void	ft_fill_map(t_tetri *cur, t_map *map, int pos, int mode)
{
	int		i;

	i = 0;
	while ((cur->piece)[i])
	{
		if (ft_isalpha((cur->piece)[i]))
			(map->box)[pos] = (mode ? (cur->piece)[i] : '.');
		pos += 1 + ((cur->piece)[i] == '\n') * (map->size - 4);
		i++;
	}
}

int		ft_test(t_tetri *cur, t_map *map, int pos)
{
	int		i;

	i = 0;
	while ((cur->piece)[i])
	{
		if (ft_isalpha((cur->piece)[i]))
			if ((pos < 0 || pos >= map->area) || (pos >= 0 && pos < map->area
			&& ft_isalpha((map->box)[pos])) || (pos >= 0 && pos < map->area
				&& (map->box)[pos] == '\n'))
				return (0);
		if (pos >= 0 && pos < map->area && (map->box)[pos] == '\n'
		&& ft_isalpha((cur->piece)[i]))
			return (0);
		pos += 1 + ((cur->piece)[i] == '\n') * (map->size - 4);
		i++;
	}
	return (1);
}

int		ft_backtracking(t_tetri *tetri, t_map *map, int pos)
{
	t_tetri	*cur;

	if (ft_resting_pieces(tetri) == 0)
		return (1);
	cur = tetri;
	while (pos < map->area)
	{
		while (cur && cur->placed)
			cur = cur->next;
		if (ft_test(cur, map, pos))
		{
			ft_fill_map(cur, map, pos, 1);
			cur->placed = 1;
			if (ft_backtracking(tetri, map, -1 * map->area))
				return (1);
			ft_fill_map(cur, map, pos, 0);
			cur->placed = 0;
		}
		pos++;
	}
	return (0);
}

t_map	*ft_solve(t_tetri *tetri)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = ft_sqrt_app(ft_list_size(tetri) * 4);
	map->box = NULL;
	while (map->size <= 104)
	{
		map->area = map->size * (map->size + 1);
		map->box = ft_strnew(map->area);
		i = 0;
		while (i < map->area)
		{
			(map->box)[i] = (i - map->size) % (map->size + 1) == 0 ? '\n' : '.';
			i++;
		}
		(map->box)[i] = '\0';
		if (ft_backtracking(tetri, map, -1 * map->area))
			return (map);
		(map->size)++;
	}
	return (NULL);
}
