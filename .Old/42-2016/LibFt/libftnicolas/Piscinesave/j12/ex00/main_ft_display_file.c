/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_display_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:15:48 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:17:23 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[2];

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		while ((ret = read(fd, buf, 1)) != 0)
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		if ((close(fd)) == -1)
			return (-1);
	}
	if (argc == 1)
		ft_putstr_stderr("File name missing.\n");
	if (argc > 2)
		ft_putstr_stderr("Too many arguments.\n");
	return (0);
}
