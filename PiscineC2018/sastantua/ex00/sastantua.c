/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:17:16 by flklein           #+#    #+#             */
/*   Updated: 2018/09/01 19:17:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_max(int size)
{
	int		floor_add;
	int		max_width;
	int		floor;

	max_width = 7;
	floor_add = 2;
	floor = 2;
	while (floor <= size)
	{
		max_width += 2 * (floor + 2);
		if (floor % 2 == 0)
			floor_add += 2;
		floor++;
		max_width += floor_add;
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
	printf("%d\n", find_max(atoi(av[1])));
	return (ac);
}
