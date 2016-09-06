/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:21:10 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:36:50 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_end_hex(char *tab, int *count_valid, int *char_nb, int letter)
{
	if (count_valid[1] == 0 && (count_valid[0] < 16 && count_valid[0] != 0))
	{
		tab[count_valid[0]] = '\0';
		display_count_hex(char_nb, count_valid);
		ft_putchar(' ');
		display_tab_hex(tab);
		display_space_hex(count_valid);
		*char_nb = *char_nb + count_valid[0];
	}
	if (letter != 0)
	{
		display_count_hex(char_nb, count_valid);
		ft_putchar('\n');
	}
}

void	read_and_stock_hex(char *tab, int *count_valid, int *char_nb, int fd)
{
	char	buf[2];
	char	prev_tab[17];
	int		identical;

	identical = 0;
	while (read(fd, buf, 1) != 0)
	{
		tab[count_valid[0]] = buf[0];
		count_valid[0]++;
		if (count_valid[0] == 16)
		{
			tab[16] = '\0';
			prev_tab[16] = '\0';
			if (ft_strcmp(tab, prev_tab) == 0)
				tab_cmp(count_valid, char_nb, &identical);
			else
			{
				ft_strcpy(tab, prev_tab);
				identical = 0;
				display_hex(tab, count_valid, char_nb);
			}
			count_valid[0] = 0;
		}
	}
}

int		open_hex(char *av, char *tab, int *count_valid, int *char_nb)
{
	int		fd;
	char	buf[2];
	int		letter;

	letter = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, buf, 1) != 0)
	{
		if (buf[0] != '\0')
			letter++;
	}
	if (close(fd) == -1)
		return (-1);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	read_and_stock_hex(tab, count_valid, char_nb, fd);
	count_valid[1]--;
	if (close(fd) == -1)
		return (-1);
	return (letter);
}

int		browse_hex(char **av, int ac, int *count_valid, int *char_nb)
{
	int		i;
	char	tab[17];
	int		ret;
	int		ret2;
	int		letter;

	i = 1;
	letter = 0;
	while (i < ac)
	{
		ret = file_is_invalid_hex(av[i]);
		if (ret == -1)
			return (-1);
		if (ret == 0)
		{
			ret2 = open_hex(av[i], tab, count_valid, char_nb);
			if (ret2 == -1)
				return (-1);
			letter = letter + ret2;
		}
		i++;
	}
	display_end_hex(tab, count_valid, char_nb, letter);
	return (0);
}

int		ft_hexdump(char **av, int ac)
{
	int		char_nb;
	int		count_valid[2];

	char_nb = 0;
	init_count_valid_hex(count_valid);
	if (check_valid_files_hex(av, ac, count_valid) == -1)
		return (-1);
	if (browse_hex(av, ac, count_valid, &char_nb) == -1)
		return (-1);
	return (0);
}
