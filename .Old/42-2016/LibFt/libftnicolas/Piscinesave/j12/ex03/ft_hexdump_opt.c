/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:23:04 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 12:37:04 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	display_end_opt(char *str, int *count_valid, int *char_nb, int letter)
{
	int		option_nb;

	str[count_valid[0]] = '\0';
	if (count_valid[1] == 0 && (count_valid[0] < 16 && count_valid[0] != 0))
	{
		option_nb = count_valid[2];
		while (option_nb != 0)
		{
			display_count_opt(char_nb);
			ft_putstr("  ");
			display_tab_opt(str);
			display_space_opt(count_valid);
			display_char_opt(str);
			ft_putchar('\n');
			option_nb--;
		}
		*char_nb = *char_nb + count_valid[0];
	}
	if (letter != 0)
	{
		display_count_opt(char_nb);
		ft_putchar('\n');
	}
}

void	read_and_stock_opt(char *tab, int *count_valid, int *char_nb, int fd)
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
				display_opt(tab, count_valid, char_nb);
			}
			count_valid[0] = 0;
		}
	}
}

int		open_opt(char *av, char *tab, int *count_valid, int *char_nb)
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
	read_and_stock_opt(tab, count_valid, char_nb, fd);
	count_valid[1]--;
	if (close(fd) == -1)
		return (-1);
	return (letter);
}

int		browse_opt(char **av, int ac, int *count_valid, int *char_nb)
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
		ret = file_is_invalid_opt(av[i]);
		if (ret == -1)
			return (-1);
		if (ret == 0)
		{
			ret2 = open_opt(av[i], tab, count_valid, char_nb);
			if (ret2 == -1)
				return (-1);
			letter = letter + ret2;
		}
		i++;
	}
	display_end_opt(tab, count_valid, char_nb, letter);
	return (0);
}

int		ft_hexdump_opt(char **av, int ac, int option_nb)
{
	int		char_nb;
	int		count_valid[3];

	char_nb = 0;
	init_count_valid_opt(count_valid, option_nb);
	if (check_valid_files_opt(av, ac, count_valid) == -1)
		return (-1);
	if (browse_opt(av, ac, count_valid, &char_nb) == -1)
		return (-1);
	return (0);
}
