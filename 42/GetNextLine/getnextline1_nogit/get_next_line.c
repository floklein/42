/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:29:55 by fklein            #+#    #+#             */
/*   Updated: 2016/09/06 17:52:20 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			i;
	char		*tmp;
	int			r;
	char		*c;

	i = 0;
	if (!rest)
		if (!(rest = (char *)realloc(rest, sizeof(char) * BUFF_SIZE)))
			return (-1);
	if (!(tmp = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!(c = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while (rest[i])
	{
		tmp[i] = rest[i];
		if (rest[i] == '\n' || rest[i] == 'EOF')
		{
			*line = (char *)ft_strjoin((*line), tmp);
			rest = rest + i;
			return (1);
		}
		i++;
	}
	printf("rest : ~%s~ -- tmp : ~%s~\n", rest, tmp);
	i = 0;
	ft_strclr(tmp);
	*line = ft_strjoin((*line), rest);
	printf("line : ~%s~\n", *line);
	while ((r = read(fd, c, BUFF_SIZE)) > 0)
	{
		printf("--- read : ~%s~ | line : ~%s~\n", c, *line);
		while (c[i])
		{
			tmp[i] = c[i];
			printf("------ tmp : ~%s~ / c : ~%s~ / c[i] : ~%c~\n", tmp, c, c[i]);
			if (c[i] == '\n')
			{
				*line = ft_strjoin((*line), tmp);
				printf("XXXX line finale : ~%s~ XXXX\n", *line);
				rest = &c[i + 1];
				return (1);
			}
			i++;
		}
		i = 0;
		ft_strclr(tmp);
		*line = ft_strjoin((*line), c);
		ft_strclr(c);
	}
	if (r == 0)
		return (0);
	return (-1);
}


int		main(void)
{
	char	**next;
	int		fd;

	if (!(next = (char **)malloc(sizeof(char*))))
		return (-1);
	next = NULL;
	fd = open("test", O_RDONLY, S_IREAD);
	get_next_line(fd, next);
	printf("%s\n", *next);
	//get_next_line(fd, &next);
	//printf("%s\n", next);
	//get_next_line(fd, &next);
	//printf("%s\n", next);
	return (0);
}
