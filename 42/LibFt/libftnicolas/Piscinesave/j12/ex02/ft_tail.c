/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:36:15 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/08 11:26:33 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		count_arg(int ac, char **av)
{
	int		arg_nb;
	int		i;

	arg_nb = 0;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == 'c')
		{
			if (av[i][2] != '\0')
				i++;
			else
			{
				i++;
				i++;
			}
		}
		else
		{
			arg_nb++;
			i++;
		}
	}
	return (arg_nb);
}

int		disp_file_end(int bytes_nb, char *av, int fd)
{
	int		seek;
	int		count;
	char	buf[2];

	seek = 0;
	count = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, buf, 1) != 0)
		seek++;
	if ((close(fd) == -1))
		return (-1);
	seek = seek - bytes_nb;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, buf, 1) != 0)
	{
		count++;
		buf[1] = '\0';
		if (count >= seek)
			ft_putstr(buf);
	}
	if ((close(fd) == -1))
		return (-1);
	return (0);
}

int		disp_file_begin(int bytes_nb, char *av, int fd)
{
	int		count;
	char	buf[2];

	count = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, buf, 1) != 0)
	{
		count++;
		buf[1] = '\0';
		if (count >= bytes_nb)
			ft_putstr(buf);
	}
	if ((close(fd) == -1))
		return (-1);
	return (0);
}

int		display_file(char *av, int plus, int bytes_nb, int *arg_nb)
{
	int		fd;

	errno = 0;
	if (isnt_dir(av, arg_nb) == 0)
	{
		if ((fd = open(av, O_RDONLY)) == -1)
			display_errno(av);
		if ((close(fd)) == -1)
			return (-1);
		if (plus == 0)
		{
			bytes_nb = bytes_nb - 1;
			display_header(av, arg_nb);
			if (disp_file_end(bytes_nb, av, fd) == -1)
				return (-1);
		}
		if (plus > 0)
		{
			display_header(av, arg_nb);
			if (disp_file_begin(bytes_nb, av, fd) == -1)
				return (-1);
		}
	}
	return (0);
}

void	browse_arg(char **av, int ac, int ret, int bytes_nb)
{
	int		i;
	int		arg_nb[2];

	i = 1;
	arg_nb[0] = count_arg(ac, av);
	arg_nb[1] = 0;
	while (i < ac)
	{
		if (arg_nb[0] == 0 || (av[i][0] == '-' && av[i][1] == '\0'))
			read_stdin(av[i], arg_nb);
		if (av[i][0] == '-' && av[i][1] == 'c')
		{
			if (av[i][2] != '\0')
				i++;
			else
				i = i + 2;
		}
		else
		{
			display_file(av[i], ret, bytes_nb, arg_nb);
			i++;
		}
	}
}
