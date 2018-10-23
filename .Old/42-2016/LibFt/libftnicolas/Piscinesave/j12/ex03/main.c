/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:24:42 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/08 11:32:04 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_invalid_fd(char *av)
{
	ft_putstr_stderr("hexdump: ");
	ft_putstr_stderr(av);
	ft_putstr_stderr(": Bad file descriptor\n");
}

int		check_option(char *av, int *option_nb)
{
	if (av[1] == 'C')
	{
		if (av[2] == '\0')
			*option_nb = *option_nb + 1;
		else
		{
			display_invalid(av[2]);
			return (-1);
		}
	}
	else
	{
		display_invalid(av[1]);
		return (-1);
	}
	return (0);
}

int		check_valid_fd(char *av, int *valid_fd)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd != -1)
	{
		*valid_fd = *valid_fd + 1;
		if (close(fd) == -1)
			return (-1);
	}
	return (0);
}

int		check_arg(char **av, int ac, int *option_nb, int *arg_nb)
{
	int		i;
	int		valid_fd;

	i = 1;
	valid_fd = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			if (check_option(av[i], option_nb) == -1)
				return (-1);
			else
				i++;
		}
		else
		{
			check_valid_fd(av[i], &valid_fd);
			*arg_nb = *arg_nb + 1;
			i++;
		}
	}
	return (valid_fd);
}

int		main(int argc, char **argv)
{
	int		arg_nb;
	int		option_nb;
	int		valid_fd;

	arg_nb = 0;
	option_nb = 0;
	if ((valid_fd = check_arg(argv, argc, &option_nb, &arg_nb)) == -1)
		return (-1);
	if (argc == 1 || (arg_nb == 0 && option_nb == 0))
		ft_hexdump_input();
	else if (arg_nb == 0 && option_nb > 0)
		ft_hexdump_inopt(option_nb);
	else if (arg_nb > 0 && option_nb > 0)
	{
		if (ft_hexdump_opt(argv, argc, option_nb) == -1)
			return (-1);
	}
	else
	{
		if (ft_hexdump(argv, argc) == -1)
			return (-1);
	}
	if (valid_fd == 0 && arg_nb > 0)
		display_invalid_fd(argv[argc - 1]);
	return (0);
}
