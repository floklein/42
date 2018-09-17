/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:34:36 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 01:04:27 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_display_tail(char *str, int bytes, int plus)
{
	int		len;

	len = ft_strlen(str);
	if (plus)
	{
		len = 0;
		bytes = -bytes;
	}
	bytes = (bytes > len ? len : bytes);
	ft_putstr(str + len - bytes);
}

void	ft_read_file(char *file, int bytes, int plus)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_file_error(file);
	else
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return ;
		str[0] = '\0';
		while ((r = read(fd, buf, BUF_SIZE)))
		{
			buf[r] = '\0';
			str = ft_strjoin(str, buf);
		}
		ft_display_tail(str, bytes, plus);
	}
	if ((r = close(fd)) == -1)
		return ;
}

void	ft_tail(int ac, char **av, int bytes, int plus)
{
	int		i;

	i = 3;
	while (i < ac)
	{
		if (ac > 4)
		{
			ft_putstr("==> ");
			ft_putstr(av[i]);
			ft_putstr(" <==\n");
		}
		ft_read_file(av[i], bytes, plus);
		if (ac > 4 && i < ac - 1)
			ft_putstr("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac == 2 && ft_strcmp(av[1], "-c") == 0)
			ft_usage_error();
		else if (ft_strcmp(av[1], "-c") == 0)
		{
			if (is_numeric(av[2]))
			{
				if (av[2][0] == '-' || (av[2][0] >= '0' && av[2][0] <= '9'))
					ft_tail(ac, av, ft_abs(ft_atoi(av[2])), 0);
				else
					ft_tail(ac, av, ft_abs(ft_atoi(av[2])), 1);
			}
			else
				ft_offset_error(av[2]);
		}
	}
	return (0);
}
