/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:34:36 by flklein           #+#    #+#             */
/*   Updated: 2018/09/17 19:59:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_file_error(char *file)
{
	ft_putstr_err("tail: ");
	ft_putstr_err(file);
	if (errno == EACCES)
		ft_putstr_err(": Permission denied\n");
	else
		ft_putstr_err(": No such file or directory\n");
}

void	ft_display_tail(char *str)
{
	ft_putstr(str);
}

void	ft_read_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_file_error(file);
	else
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return ;
		str[0] = '\0';
		while ((r = read(fd, buf, BUF_SIZE)))
		{
			buf[r] = '\0';
			str = ft_strjoin(str, buf);
		}
		ft_display_tail(str);
	}
	if ((r = close(fd)) == -1)
		return ;
}

void	ft_tail(int ac, char **av, int bytes)
{
	int		i;

	i = 3;
	while (i < ac)
	{
		if (ac > 4)
		{
			ft_putstr("==> ");
			ft_putstr(av[i]);
			ft_putstr(" <==\n");
		}
		ft_read_file(av[i]);
		i++;
	}
	bytes = 0;
}

void	ft_offset_error(char *offset)
{
	ft_putstr("tail: illegal offset -- ");
	ft_putstr(offset);
	ft_putstr("\n");
}

int		main(int ac, char **av)
{
	if (ac > 3 && ft_strcmp(av[1], "-c") == 0)
	{
		if (is_numeric(av[2]))
			ft_tail(ac, av, ft_atoi(av[2]));
		else
			ft_offset_error(av[2]);
	}
	return (0);
}
