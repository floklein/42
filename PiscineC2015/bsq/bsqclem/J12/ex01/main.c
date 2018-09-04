/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:27:29 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 19:03:25 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int		ft_read(char *s, char *file)
{
	int		i;
	int		fd;

	i = 0;
	if ((fd = open(s, O_RDONLY)) == -1)
	{
		ft_putstr(2, s);
		ft_putstr(2, " : open () error\n");
		return (0);
	}
	read(fd, file, BUFFSIZE);
	if (close(fd) == -1)
	{
		ft_putstr(2, s);
		ft_putstr(2, " : close () error\n");
		return (0);
	}
	return (ft_strlen(file));
}

void	ft_cat_files(int ac, char **av)
{
	int		i;
	char	files[BUFFSIZE + 1];
	int		size;

	size = 0;
	i = 0;
	while (++i < ac)
		size += ft_read(av[i], files + size) - 1;
	ft_putnstr(1, files, size);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	ft_cat_files(ac, av);
	return (0);
}
