/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:46:10 by fklein            #+#    #+#             */
/*   Updated: 2017/04/05 21:59:34 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	str_to_map(int ***map, char ***map_str, int map_width, int map_height)
{
	int	i;
	int	j;

//	printf("--starting str to map\n");
	if (!((*map) = (int **)malloc(sizeof(int *) * map_height)))
		return (0);
//	printf("--map alloc\n");
	i = 0;
	while (i < map_height)
	{
		j = 0;
		if (!((*map)[i] = (int *)malloc(sizeof(int) * map_width)))
			return (0);
		while (j < map_width)
		{
			(*map)[i][j] = ft_atoi(map_str[i][j]);
//			printf("------map i: %d / j: %d num: ~%d~\n", i, j, (*map)[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}

int	file_to_str_to_map(int ***map, char *file, int map_width, int map_height)
{
	char	***map_str;
	int	fd;
	int	i;
	char	*line;

//	printf("--starting file to map\n");
	if (!(map_str = (char ***)malloc(sizeof(char **) * map_height)))
		return (0);
//	printf("--map_str alloc\n");
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (i < map_height)
	{
		if(!(map_str[i] = (char **)malloc(sizeof(char*) * map_width)))
			return (0);
//		printf("---get next line\n");
		get_next_line(fd, &line);
//		printf("----line: %s\n", line);
		map_str[i] = ft_strsplit(line, ' ');
//		printf("----line %d stocked in str\n", i);
		i++;
	}
//	printf("--end of stock in map_str\n");
	str_to_map(map, map_str, map_width, map_height);
	return (1);
}

int	main(int argc, char **argv)
{
	int	**map;
	int	map_width = 19;
	int	map_height = 11;
	int	i;
	int	j;

	if (argc != 2)
		ft_putstr_fd("Usage: ./fdf <filename> [ case_size z_size ]\n", 2);
	else if (0) //checkfile
		ft_putstr_fd("file error\n", 2);
	else if (!(file_to_str_to_map(&map, argv[1], map_width, map_height)))
		ft_putstr_fd("map error \n", 2);
	else
	{
		printf("PRINTED :\n");
		i = 0;
		while (i < map_height)
		{
			j = 0;
			while (j < map_width)
			{
				printf("%d ", map[i][j]);
				if (map[i][j] < 10)
					printf(" ");
				j++;
			}
			printf("\n");
			i++;
		}
	}
	return (0);
}
