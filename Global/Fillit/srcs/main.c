/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:23:17 by flklein           #+#    #+#             */
/*   Updated: 2018/11/23 19:32:58 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_tetri	*tetri;
	t_map	*map;

	if (ac != 2)
		return (ft_putstr_int("usage: ./fillit <file>\n", 0));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (ft_putstr_int("error\n", 0));
	if (!(tetri = ft_parse(fd)))
		return (ft_putstr_int("error\n", 0));
	if (!(map = ft_solve(tetri)))
		return (ft_putstr_int("error\n", 0));
	ft_putstr(map->box);
	close(fd);
	return (0);
}
