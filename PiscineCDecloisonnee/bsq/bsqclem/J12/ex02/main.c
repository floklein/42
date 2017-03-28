/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:27:29 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 21:53:32 by cchaumar         ###   ########.fr       */
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

void	ft_tail_files(int ac, char **av, int type)
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

int		ft_check_args(ac, av)
{
	if (ac < 4 && ft_strcmp(av[1], "-c") == 0)
	{
		ft_putstr(2, "Option requires an argument -- c");
		return (-1);
	}
	if (ac < 4)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		type;

	if (ac == 1)
		return (0);
	type = ft_check_args(ac, av);
   	if ( type == -1)
		return (1);
	ft_tail_files(ac, av, type);
	return (0);
}
