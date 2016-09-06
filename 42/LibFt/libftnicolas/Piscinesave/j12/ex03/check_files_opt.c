/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:15:21 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:16:05 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		isnt_dir_display_opt(char *av)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(av, O_DIRECTORY);
	if (fd == -1)
		return (0);
	if (fd != -1)
	{
		ft_putstr_stderr("hexdump: ");
		ft_putstr_stderr(av);
		ft_putstr_stderr(": is a directory\n");
		close(fd);
	}
	return (ret);
}

int		isnt_dir_opt(char *av)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(av, O_DIRECTORY);
	if (fd == -1)
		return (0);
	if (fd != -1)
		close(fd);
	return (ret);
}

int		file_is_invalid_opt(char *av)
{
	int		fd;

	errno = 0;
	if (av[0] != '-' && av[1] != 'C')
	{
		if (isnt_dir_display_opt(av) == 0)
		{
			if ((fd = open(av, O_RDONLY)) == -1)
			{
				display_errno(av);
				return (1);
			}
			else
			{
				if (close(fd) == -1)
					return (-1);
				return (0);
			}
		}
		else
			return (1);
	}
	else
		return (1);
}

int		check_valid_files_opt(char **av, int ac, int *count_valid)
{
	int		i;
	int		fd;

	i = 1;
	while (i < ac)
	{
		if (isnt_dir_opt(av[i]) == 0)
		{
			if (av[i][0] != '-' && av[i][1] != 'C')
			{
				if ((fd = open(av[i], O_RDONLY)) != -1)
				{
					count_valid[1]++;
					if (close(fd) == -1)
						return (-1);
				}
			}
		}
		i++;
	}
	return (0);
}
