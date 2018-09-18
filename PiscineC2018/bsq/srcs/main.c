/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:34:36 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 12:17:47 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_display_standard(void)
{
	char	buf[BUF_SIZE + 1];
	int		r;

	while (1)
	{
		r = read(0, buf, BUF_SIZE);
		buf[r] = '\0';
		ft_putstr(buf);
	}
}

void	ft_display_error(void)
{
	ft_putstr_err("map error\n");
}

char	*ft_display_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_display_error();
	else
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		while ((r = read(fd, buf, BUF_SIZE)))
		{
			buf[r] = '\0';
			str = ft_strjoin(str, buf);
		}
	}
	if ((r = close(fd)) == -1)
		return (NULL);
	return (str);
}

int		main(int ac, char **av)
{
	int		i;
	char	*map;

	if (ac == 1)
		ft_display_standard();
	else
	{
		i = 1;
		while (i < ac)
		{
			map = ft_display_file(av[i]);
			ft_putstr(map);
			i++;
		}
	}
	return (0);
}
