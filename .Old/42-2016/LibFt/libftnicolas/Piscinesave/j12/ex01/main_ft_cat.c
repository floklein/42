/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:21:40 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:34:17 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		isnt_dir(char *av)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(av, O_DIRECTORY);
	if (fd == -1)
		return (0);
	if (fd != -1)
	{
		ft_putstr_stderr("cat: ");
		ft_putstr_stderr(av);
		ft_putstr_stderr(": Is a directory\n");
		close(fd);
	}
	return (ret);
}

void	display_stdin(void)
{
	char	buf[2];

	while (read(0, buf, 1))
	{
		buf[1] = '\0';
		ft_putstr(buf);
	}
}

void	display_err(char *arg_name)
{
	if (errno == EACCES)
	{
		ft_putstr_stderr("cat: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": Permission denied\n");
	}
	else if (errno == ENOENT)
	{
		ft_putstr_stderr("cat: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": No such file or directory\n");
	}
}

void	ft_cat(int fd)
{
	char	buf[2];

	while (read(fd, buf, 1))
	{
		buf[1] = '\0';
		ft_putstr(buf);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	if (argc == 1)
		display_stdin();
	while (i < argc)
	{
		errno = 0;
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			display_stdin();
		if (isnt_dir(argv[i]) == 0)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				display_err(argv[i]);
			else
			{
				ft_cat(fd);
				if (close(fd) == -1)
					return (-1);
			}
		}
		i++;
	}
	return (0);
}
