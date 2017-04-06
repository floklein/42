/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:31:17 by fklein            #+#    #+#             */
/*   Updated: 2017/04/06 12:35:28 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	no_data()
{
	ft_putstr_fd("No data found.\n", 2);
	return (0);
}

int	no_file(char *file)
{
	ft_putstr_fd("No file ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	wrong_length()
{
	ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
	return (0);
}

int	check_file(int *fd, char *file, int *map_width, int *map_height)
{
	int	err;
	char	*ch;
	int	only_spaces;
	int	current_width;

	if ((*fd = open(file, O_RDONLY)) == -1)
		return (no_file(file));
	if (!(ch = (char *)malloc(sizeof(char) * 1)))
		return (0);
	only_spaces = 1;
	current_width = 0;
	while ((err = read(*fd, ch, 1)) > 0)
	{
		printf("--ch: ~%c~\n", ch[0]);
		current_width++;
		printf("--current width: %d\n", current_width);
		printf("--map width: %d\n", *map_width);
		if (ch[0] != ' ' && ch[0] != '\n')
			only_spaces = 0;
		if (ch[0] == '\n')
		{
			(*map_height)++;
			if (*map_width != -1 && current_width != *map_width)
				return (wrong_length());
			else
				*map_width = current_width;
			current_width = 0;
		}
	}
	printf("final width: %d\n", *map_width);
	printf("final height: %d\n", *map_height);
	if (only_spaces)
		return (no_data());
	return (1);
}
