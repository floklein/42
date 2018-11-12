/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:03 by flklein           #+#    #+#             */
/*   Updated: 2018/11/12 16:30:09 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*from_nl(char *str)
{
	
}

char	*until_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (str + (i >= 0 ? i : 0));
}

int		get_next_line(const int fd, char **line)
{
	static char	rest;
	int			r;
	char		buf[BUFF_SIZE + 1];

	while (r = read (fd, buf, BUFF_SIZE))
	{
		buf[r] ='\0';
		*line = ft_strjoin(*line, until_nl(buf));
		rest = from_nl(buf);
	}
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
}
