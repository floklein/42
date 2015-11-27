/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 00:25:29 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 16:15:02 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <errno.h>

void	standard(void)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	
	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
		if (ret == -1)
			return ;
	}
}

void	display(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_error("cat: ");
		ft_putstr_error(str);
		if (errno == EACCES)
			ft_putstr_error(": Permission denied\n"); 
		else
			ft_putstr_error(": No such file or directory\n"); 
	}
	else
	{
		while ((ret = read(fd, buf, BUF_SIZE)) != 0)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
	}
	ret = close(fd);
}

int		main(int ac, char **av)
{
	int		index;

	index = 1;
	if (ac == 1)
		standard();
	else if (ac > 1)
		while (index < ac)
		{
			display(av[index]);
			index++;
		}
	return (0);
}
