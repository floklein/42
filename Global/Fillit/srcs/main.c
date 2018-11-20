/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:03:58 by flklein           #+#    #+#             */
/*   Updated: 2018/11/20 19:19:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_parse(int fd)
{
	t_tetri	*start;
	int		r;
	char	*line;
	int		num_l;

	r = 1;
	while (r)
	{
		num_l = 0;
		while (r)
		{
			r = get_next_line(fd, &line);
			ft_list_push_back(&start, line);
			num_l++;
			if (ft_strlen(line) != 4 || num_l > 4)
				return (NULL);
		}
		get_next_line(fd, &line);
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
