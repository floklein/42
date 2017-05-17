/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:31:17 by fklein            #+#    #+#             */
/*   Updated: 2017/05/17 12:36:51 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	errors(int number)
{
	if (number == 1)
		ft_putstr_fd("No data found.\n", 2);
	else if (number == 2)
		ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	else if (number == 3)
		ft_putstr_fd("Usage: ./fdf <filename> [ case_size z_size ]\n", 2);
	return (0);
}

int	no_file(char *file)
{
	ft_putstr_fd("No file ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	tests(int *fd, char *ch, int *err, int *spc_cnt, int *only_spaces)
{
	if (ch[0] == ' ')
	{
		(*spc_cnt)++;
		while (ch[0] == ' ' && *err > 0)
			*err = read(*fd, ch, 1);
	}
	if (ch[0] != ' ' && ch[0] != '\n')
		*only_spaces = 0;
	return (1);
}

int	starter(int *fd, char *file, char **ch, int *only_spaces, int *spc_cnt)
{
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (no_file(file));
	if (!(*ch = (char *)malloc(sizeof(char) * 1)))
		return (0);
	*only_spaces = 1;
	*spc_cnt = 1;
	return (1);
}

int	check_file(int *fd, char *file, t_data *data)
{
	int	err;
	char	*ch;
	int	only_spaces;
	int	spc_cnt;

	if (!starter(fd, file, &ch, &only_spaces, &spc_cnt))
		return (0);
	while ((err = read(*fd, ch, 1)) > 0)
	{
		tests(fd, ch, &err, &spc_cnt, &only_spaces);
		if (ch[0] == '\n')
		{
			data->height++;
			if (data->width != -1 && spc_cnt != data->width)
				return (errors(2));
			else
				data->width = spc_cnt;
			spc_cnt = 1;
		}
	}
	close(*fd);
	if (only_spaces)
		return (errors(1));
	return (1);
}
