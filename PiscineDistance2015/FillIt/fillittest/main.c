/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:48:43 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/07 07:41:08 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_set(t_piece *tab, int count, unsigned char pos)
{
	if (count == 0)
		tab->_0 = pos;
	if (count == 1)
		tab->_1 = pos;
	if (count == 2)
		tab->_2 = pos;
	if (count == 3)
		tab->_3 = pos;
}

int		ft_fill_pieces(int fd, t_piece **tab, unsigned char pos, int count)
{
	char			c;

	while (read(fd, &c, 1) > 0)
	{
		if (pos == 0)
		{
			if ((*tab = malloc(sizeof(t_piece *))) == NULL)
				return (-1);
			count = 0;
		}
		if (c == BLOC)
			ft_set(*tab, count++, pos++);
		if (c == EMPT)
			pos++;
		if (c == LINE)
			if ((pos = (pos & 0xF0) + 0x10) == 0x40)
			{
				read(fd, &c, 1);
				pos = 0;
				tab++;
			}
	}
	return (0);
}

int		ft_check_line(int *lines, int *count, int *len, int fd)
{
	char	c;

	(*lines)++;
	if (*len != 4)
		return (-1);
	else
		*len = 0;
	if (*lines == 4)
	{
		if (*count != 4)
			return (-1);
		*lines = read(fd, &c, 1);
		if (c != LINE && *lines)
			return (-1);
		*lines = 0;
		*count = 0;
	}
	return (0);
}

int		ft_get_tet_nbr(int fd, int n_tet, int count, int lines)
{
	char	c;
	int		len;

	len = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c != BLOC && c != EMPT && c != LINE)
			return (-1);
		if (c == BLOC)
			if ((count += 1) == 5)
				return (-1);
		if (c == BLOC || c == EMPT)
			len++;
		if (c == LINE)
		{
			if (ft_check_line(&lines, &count, &len, fd) == -1)
				return (-1);
			n_tet++;
		}
	}
	return (n_tet / 4);
}

int		main(int ac, char **av)
{
	int		fd;
	int		n;
	t_piece	**tab;

	if (ac != 2)
		ft_out(USE);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_out(ERR);
	n = ft_get_tet_nbr(fd, 0, 0, 0);
	close(fd);
	if (n == -1 || n > 26)
		ft_out(ERR);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_out(ERR);
	if ((tab = malloc(sizeof(t_piece *) * (n + 1))) == NULL)
		ft_out(ERR);
	if (ft_fill_pieces(fd, tab, 0, 0) == -1)
	{
		ft_clear((void **)tab);
		ft_out(ERR);
	}
	tab[n] = NULL;
	ft_solve(tab, ft_root(n * 4), n);
	ft_clear((void **)tab);
	free(tab);
	return (0);
}
