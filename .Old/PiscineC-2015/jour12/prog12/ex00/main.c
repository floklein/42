/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 00:25:29 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 01:34:31 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	display(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	while (fd != -1 && (ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	ret = close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac != 2)
		write(2, "Too many arguments.\n", 20);
	else if (ac == 2)
		display(av[1]);
	return (0);
}
