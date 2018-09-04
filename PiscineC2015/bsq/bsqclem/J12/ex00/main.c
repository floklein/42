/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:27:29 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 14:52:53 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_display_file(char *s)
{
	int		fd;
	int		ret;
	char	buf[BUFFSIZE + 1];

	if ((fd = open(s, O_RDONLY)) == -1)
	{
		ft_putstr(2, "open () error\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr(1, buf);
	}
	if (close(fd) == -1)
	{
		ft_putstr(2, "close () error\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr(2, "file name missing.\n");
		return (1);
	}
	if (ac != 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (1);
	}
	return (ft_display_file(av[1]));
}
