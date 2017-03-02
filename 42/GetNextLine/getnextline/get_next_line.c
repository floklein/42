//
//
//
//
//
//
//
//
//
//
//
//

#include "get_next_line.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	static stockage	*stock = NULL;
	int		err;
	char		*ch;
	char		*tmp_str;

	if (!stock)
	{
		if (!(stock = (stockage *)malloc(sizeof(stockage))))
			return (-1);
		if (!(stock->tries = (int *)malloc(sizeof(int) * 1000)))
			return (-1);
		if (!(stock->files = (char ***)malloc(sizeof(char **) * 1000)))
			return (-1);
		printf("\033[31mMémoire allouée !\n");
	}
	if (stock->tries[fd] == 0)
	{
		if (!(ch = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		if (!(tmp_str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		printf("\033[31m---- Premier try pour fd%d\n", fd);
		while ((err = read(fd, ch, BUFF_SIZE)) > 0)
		{	
			printf("\033[32m-------- Buffer lu :\033[0m =%s=\n", ch);
			tmp_str = ft_strjoin(tmp_str, ch);
			printf("\033[32m-------- Etat du tmp :\033[0m\n=%s=\n", tmp_str);
			ft_strclr(ch);
		}
		stock->files[fd] = ft_strsplit(tmp_str, '\n');
		printf("\033[31m---- Tableau ajouté pour fd%d !\n", fd);
	}
	printf("\033[36mLigne à venir : -%s-\n", stock->files[fd][stock->tries[fd]]);
	printf("\033[36mPrécédente valeur de *line : #%s#\n", *line);
	*line = stock->files[fd][stock->tries[fd]];
	printf("\033[31mLigne stockée !\n");
	stock->tries[fd]++;
	if (stock->files[fd][stock->tries[fd]] == NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int	fd1;
	int	fd2;
	char	**line1;
	char	**line2;

	line1 = (char **)malloc(sizeof(char *));
	line2 = (char **)malloc(sizeof(char *));
	*line1 = (char *)malloc(sizeof(char));
	*line2 = (char *)malloc(sizeof(char));

	fd1 = open("test", O_RDONLY, S_IREAD);
	fd2 = open("test2", O_RDONLY, S_IREAD);

	while ((get_next_line(fd1, line1)) != 0)
		printf("\033[33mXXXXXXXXXXXX Ligne fd1=%d : --%s-- XXXXXXXXXXXX\n", fd1, *line1);
	printf("\033[33mXXXXXXXXXXXX Last fd1=%d : --%s-- XXXXXXXXXXXX\n", fd1, *line1);

	while ((get_next_line(fd2, line2)) != 0)
		printf("\033[33mXXXXXXXXXXXX Ligne fd2=%d : --%s-- XXXXXXXXXXXX\n", fd2, *line2);
	printf("\033[33mXXXXXXXXXXXX Last fd1=%d : --%s-- XXXXXXXXXXXX\n", fd2, *line2);
	
	close (fd1);
	close (fd2);
}
