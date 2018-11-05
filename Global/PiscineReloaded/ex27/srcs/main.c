/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:34:36 by flklein           #+#    #+#             */
/*   Updated: 2018/09/17 14:56:05 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_display_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	else
	{
		while ((r = read(fd, buf, BUF_SIZE)))
		{
			buf[r] = '\0';
			ft_putstr(buf);
		}
	}
	if ((r = close(fd)) == -1)
		return ;
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr_err("File name missing.\n");
	else if (ac == 2)
		ft_display_file(av[1]);
	else
		ft_putstr_err("Too many arguments.\n");
	return (0);
}
