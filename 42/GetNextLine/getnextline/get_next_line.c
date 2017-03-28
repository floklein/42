/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:28:23 by fklein            #+#    #+#             */
/*   Updated: 2017/03/06 14:55:36 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static stockage	*stock = NULL;
	int		err;
	char		*ch;
	char		*tmp_str;

	if (fd < 0)
		return (-1);
	if (!stock)
	{
		if (!(stock = (stockage *)malloc(sizeof(stockage)))
		|| !(stock->tries = (int *)malloc(sizeof(int) * 1000))
		|| !(stock->files = (char ***)malloc(sizeof(char **) * 1000)))
			return (-1);
		printf("\033[31m---- Mémoire allouée !\n");
	}
	if (stock->tries[fd] == 0)
	{
		if (!(ch = (char *)malloc(sizeof(char) * BUFF_SIZE))
		|| !(tmp_str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		printf("\033[31m---- Premier try pour fd=%d\n", fd);
		while ((err = read(fd, ch, BUFF_SIZE)) > 0)
		{
			printf("\033[32m-------- Buffer lu :\033[0m\n=%s=\n", ch);
			tmp_str = ft_strjoin(tmp_str, ch);
			printf("\033[32m-------- Etat du tmp :\033[0m\n=%s=\n", tmp_str);
			ft_strclr(ch);
		}
		if (err == -1 && errno == EBADF)
			return (-1);
		stock->files[fd] = ft_strsplit_mod(tmp_str, '\n');
		printf("\033[31m---- Tableau ajouté pour fd%d !\n", fd);
	}
	printf("\033[36mPrécédente valeur de *line : #%s#\n", *line);
	*line = stock->files[fd][stock->tries[fd]];
	printf("\033[31mLigne stockée !\n");
	printf("\033[33m ==> Ligne fd=%d : --%s--\n", fd, *line);
	if (stock->files[fd][stock->tries[fd] + 1] == NULL)
		return (0);
	stock->tries[fd]++;
	return (1);
}

int	main(void)
{
	int	fd0;
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line0 = NULL;
	char	*line1 = NULL;
	char	*line2 = NULL;
	char	*line3 = NULL;

	fd0 = 0;
	fd1 = open("test2", O_RDONLY, S_IREAD);
//	fd2 = open("test2", O_RDONLY, S_IREAD);
//	fd3 = open("test3", O_RDONLY, S_IREAD);

/*	printf("\033[33m ==> Output : %d\n", get_next_line(fd0, &line0));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd0, &line0));

	printf("\033[35m======================================================\n");
*/
	printf("\033[33m ==> Output : %d\n", get_next_line(fd1, &line1));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd1, &line1));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd1, &line1));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd1, &line1));
/*
	printf("\033[35m======================================================\n");

	printf("\033[33m ==> Output : %d\n", get_next_line(fd2, &line2));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd2, &line2));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd2, &line2));

	printf("\033[35m======================================================\n");

	printf("\033[33m ==> Output : %d\n", get_next_line(fd3, &line3));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd3, &line3));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd3, &line3));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd3, &line3));
	printf("\033[33m ==> Output : %d\n", get_next_line(fd3, &line3));
*/
	close (fd1);
	close (fd2);
	close (fd3);
}
