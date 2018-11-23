/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:03:58 by flklein           #+#    #+#             */
/*   Updated: 2018/11/23 19:43:56 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_piece(char *str)
{
	int		i;
	int		links;
	int		hashes;

	links = 0;
	hashes = 0;
	i = 0;
	while (str[i])
	{
		if ((i + 1) % 5 == 0 && str[i] != '\n')
			return (0);
		if ((i + 1) % 5 != 0 && str[i] != '#' && str[i] != '.')
			return (0);
		if (str[i] == '#')
		{
			hashes++;
			links += (i + 1 <= 20 ? str[i + 1] == '#' : 0)
				+ (i - 1 >= 0 ? str[i - 1] == '#' : 0)
				+ (i + 5 <= 20 ? str[i + 5] == '#' : 0)
				+ (i - 5 >= 0 ? str[i - 5] == '#' : 0);
		}
		i++;
	}
	return (hashes == 4 && links >= 6);
}

int		ft_convert(char **src, char c)
{
	int		i;

	i = 0;
	while ((*src)[i])
	{
		(*src)[i] = ((*src)[i] == '#' ? c : (*src)[i]);
		i++;
	}
	return (1);
}

t_tetri	*ft_parse(int fd)
{
	t_tetri	*tetri;
	int		r;
	char	*buf;
	char	pieces;

	if (!(buf = ft_strnew(20)))
		return (NULL);
	pieces = 'A' - 1;
	r = 1;
	tetri = NULL;
	while (r && ++pieces <= 'Z')
	{
		if ((r = read(fd, buf, 20)) < 0)
			return (NULL);
		buf[r] = '\0';
		if (r != 20 || !ft_valid_piece(buf) || !ft_convert(&buf, pieces))
			return (NULL);
		ft_list_push_back(&tetri, buf);
		if ((r = read(fd, buf, 1)) < 0)
			return (NULL);
		buf[r] = '\0';
		if (r == 1 && !ft_strequ(buf, "\n"))
			return (NULL);
	}
	return (pieces <= 'Z' ? tetri : NULL);
}
