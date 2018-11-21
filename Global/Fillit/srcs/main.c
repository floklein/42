/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:03:58 by flklein           #+#    #+#             */
/*   Updated: 2018/11/21 16:24:12 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		ft_charvalid(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

t_tetri	*ft_parse(int fd)
{
	t_tetri	*start;
	int		r;
	char	*line;
	int		num_l;
	char	*stock;

	stock = ft_strnew(0);
	num_l = 0;
	while ((r = get_next_line(fd, &line)))
	{
		if (!ft_strequ(line, "\0"))
		{
			stock = ft_strjoin(stock, line);
			if (ft_strlen(line) != 4 || !ft_charvalid(line))
				return (NULL);
			num_l++;
		}
		else
		{
			if (num_l != 4)
				return (NULL);
			printf("stock:%s\n", stock);
			ft_list_push_back(&start, stock);
			stock = ft_strnew(0);
			num_l = 0;
		}
	}
	return (start);
}

int		main(int ac, char **av)
{
	int		fd;
	t_tetri	*tetri;

	fd = open(av[1], O_RDONLY);
	tetri = ft_parse(fd);
	ft_list_foreach(tetri, &ft_putendl);
	close(fd);
	return (ac);
}
