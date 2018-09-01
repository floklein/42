/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:17:16 by flklein           #+#    #+#             */
/*   Updated: 2018/09/01 18:19:57 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_max(int size)
{
	int		floor;
	int		line;
	int		max_width;

	floor = 1;
	max_width = 3;
	while (floor <= size)
	{
		if (floor == 1)
			;
		else if (floor == 2 || floor == 3)
			max_width += 6;
		else if (floor % 2 == 1)
			max_width += 2 * floor - 1;
		else
			max_width += 2 * floor;
		line = 1;
		while (line < floor + 2)
		{
			max_width += 2;
			line++;
		}
		floor++;
	}
	return (max_width);
}

void	display_line(int s, int f, int l)
{
	int		pos;
	int		wd_f;

	wd_f = find_max(f);
	pos = 0;
	while (pos++ < (find_max(s) - (wd_f - (f + 2 - l) * 2)) / 2)
		ft_putchar(' ');
	pos = 0;
	while (pos++ < wd_f - (f + 2 - l) * 2)
	{
		if (pos == 1)
			ft_putchar('/');
		else if (pos == wd_f - (f + 2 - l) * 2)
			ft_putchar('\\');
		else if (f == s && l > 3 - f % 2
		&& (pos >= (wd_f + 1 - (f + 2 - l) * 2) / 2 - (s - 1) / 2
		&& pos <= (wd_f + 1 - (f + 2 - l) * 2) / 2 + (s - 1) / 2))
			ft_putchar(s > 4 && l == 4 - f % 2 + (f - 1) / 2
	&& pos == (wd_f + 1 - (f + 2 - l) * 2) / 2 + (s - 1) / 2 - 1 ? '$' : '|');
		else
			ft_putchar('*');
	}
	ft_putchar('\n');
}

void	display_floor(int size, int floor)
{
	int		line;

	line = 1;
	while (line <= floor + 2)
	{
		display_line(size, floor, line);
		line++;
	}
}

void	sastantua(int size)
{
	int		floor;

	floor = 1;
	while (floor <= size)
	{
		display_floor(size, floor);
		floor++;
	}
}

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	sastantua(atoi(av[1]));
	return (ac);
}
