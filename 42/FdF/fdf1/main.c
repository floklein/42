/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:46:10 by fklein            #+#    #+#             */
/*   Updated: 2017/07/23 20:22:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	str_to_map(char ***map_str, t_data *data)
{
	int	i;
	int	j;

	printf("strtomap\n");
	if (!((data->tab) = (int **)malloc(sizeof(int *) * data->height)))
		return (0);
	i = 0;
	printf("height: %d, width: %d\n", data->height, data->width);
	while (i < data->height)
	{
		j = 0;
		if (!(data->tab[i] = (int *)malloc(sizeof(int) * data->width)))
			return (0);
		while (j < data->width)
		{
			printf("str[%d][%d]: %s\n", i, j, map_str[i][j]);
			data->tab[i][j] = ft_atoi(map_str[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}

int	file_to_str_to_map(char *file, t_data *data)
{
	char	***map_str;
	int	i;
	int	fd;
	char	*line;

	printf("filetostrmap\n");
	if (!(map_str = (char ***)malloc(sizeof(char **) * data->height)))
		return (0);
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (no_file(file));
	while (i < data->height)
	{
		if(!(map_str[i] = (char **)malloc(sizeof(char*) * data->width)))
			return (0);
		get_next_line(fd, &line);
		map_str[i] = ft_strsplit(line, ' ');
		i++;
	}
	close(fd);
	str_to_map(map_str, data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int	fd;
	int	i;
	int	j;

	if (argc != 2)
		return (errors(3));
	else if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	data->width = -1;
	data->height = 0;
	if (!check_file(&fd, argv[1], data))
		return (0);
	else if (!file_to_str_to_map(argv[1], data))
		return (0);
	else
	{
		printf("PRINTED:\n");
		i = 0;
		while (i < data->height)
		{
			j = 0;
			while (j < data->width)
			{
				printf("%d ", data->tab[i][j]);
				if (data->tab[i][j] < 10)
					printf(" ");
				j++;
			}
			printf("\n");
			i++;
		}
		fdf(data);
	}
	return (0);
}
