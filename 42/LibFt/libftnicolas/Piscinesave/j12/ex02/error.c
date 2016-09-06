/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:34:46 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/08 11:37:09 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_header(char *av, int *arg_nb)
{
	if (arg_nb[0] > 1)
	{
		if (arg_nb[1] == 0)
		{
			ft_putstr("==> ");
			ft_putstr(av);
			ft_putstr(" <==\n");
			arg_nb[1]++;
		}
		else
		{
			ft_putstr("\n==> ");
			ft_putstr(av);
			ft_putstr(" <==\n");
		}
	}
}

void	read_stdin(char *av, int *arg_nb)
{
	char	buf[2];

	if (av[0] == '-' && av[1] == '\0')
		arg_nb[0]--;
	if (arg_nb[0] > 0)
		ft_putstr("\n==> standard input <==\n");
	while (1)
		read(0, buf, 1);
}

int		isnt_dir(char *av, int *arg_nb)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(av, O_DIRECTORY);
	if (fd == -1)
		return (0);
	if (fd != -1)
	{
		display_header(av, arg_nb);
		close(fd);
	}
	return (ret);
}

void	display_error(char *arg, int case_nb)
{
	int	i;

	if (case_nb == 1 || case_nb == 2)
	{
		if (case_nb == 1)
			i = 2;
		if (case_nb == 2 || case_nb == 3)
			i = 0;
		ft_putstr_stderr("tail: illegal offset -- ");
		while (arg[i])
		{
			if ((arg[i] == '-' && case_nb == 1 && i == 2) ||
			(arg[i] == '-' && case_nb == 2 && i == 0))
				i++;
			ft_putchar_stderr(arg[i]);
			i++;
		}
		ft_putchar_stderr('\n');
	}
}

void	display_errno(char *arg_name)
{
	if (errno == EACCES)
	{
		ft_putstr_stderr("tail: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": Permission denied\n");
	}
	else if (errno == ENOENT)
	{
		ft_putstr_stderr("tail: ");
		ft_putstr_stderr(arg_name);
		ft_putstr_stderr(": No such file or directory\n");
	}
}
