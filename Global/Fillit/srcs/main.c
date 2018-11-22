/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:14:54 by flklein           #+#    #+#             */
/*   Updated: 2018/11/22 19:33:02 by flklein          ###   ########.fr       */
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
		i++;
		pos += 1 + !(i % 4) * (map->size - 4);
	}
}

int		ft_test(t_tetri *cur, t_map *map, int pos)
{
	int		i;

	i = 0;
	while ((cur->piece)[i])
	{
		if (pos >= 0 && pos <= map->size * map->size
		&& ft_isalpha((cur->piece)[i]) && ft_isalpha((map->box)[pos]))
			return (0);
		i++;
		pos += 1 + !(i % 4) * (map->size - 4);
	}
	return (1);
}

int		ft_backtracking(t_tetri *tetri, t_map *map, int pos)
{
	t_tetri	*cur;

	if (ft_resting_pieces(tetri) == 0)
		return (1);
	cur = tetri;
	while (pos <= map->size * map->size)
	{
		while (cur && cur->placed)
			cur = cur->next;
		if (ft_test(cur, map, pos))
		{
			ft_fill_map(cur, map, pos, 1);
			cur->placed = 1;
			if (ft_backtracking(tetri, map, -15))
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

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = 2;
	while (map->size <= 104)
	{
		map->box = ft_strnew(map->size * map->size);
		if (ft_backtracking(tetri, map, -15))
			return (map);
		(map->size)++;
	}
	return (NULL);
}

void	ft_display(t_map *map)
{
	int		i;

	i = 0;
	while ((map->box)[i])
	{
		ft_putchar((map->box[i]));
		if ((i + 1) % map->size == 0)
			ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_tetri	*tetri;
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_int("usage\n", 0));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_putstr_int("error\n", 0));
	if (!(tetri = ft_parse(fd)))
		return (ft_putstr_int("error\n", 0));
	ft_putendl("TETRI:");
	ft_list_foreach(tetri, &ft_putendl);
	map = ft_solve(tetri);
	ft_putendl("MAP:");
	ft_display(map);
	close(fd);
	return (0);
}
