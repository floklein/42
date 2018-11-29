/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:30:38 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 21:06:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (j < map->columns)
		{
			ft_putnbr(map->tab[i][j++]);
			j < map->columns ? ft_putchar('\t') : 0;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_count_values(char *str)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			nb++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (nb);
}

t_map	*ft_parse(char *file)
{
	t_map	*map;
	int		fd;
	int		fd2;
	char	*line;
	int		i;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		map->lines++;
		map->columns = ft_count_values(line);
	}
	if ((fd2 = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (!(map->tab = (int **)malloc(sizeof(int *) * (map->lines + 1))))
		return (NULL);
	i = 0;
	while (get_next_line(fd2, &line) > 0)
		map->tab[i++] = ft_intsplitstr(line, " \t\n");
	map->tab[i] = NULL;
	close(fd);
	close(fd2);
	return (map);
}
