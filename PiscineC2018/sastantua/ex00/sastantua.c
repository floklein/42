/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:49:59 by flklein           #+#    #+#             */
/*   Updated: 2018/08/30 18:34:49 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fake_pos(int size, int floor, int *max_width)
{
	int		line;
	int		pos;

	while (floor <= size)
	{
		line = 1;
		while (line <= floor + 2)
		{
			pos = 1;
			while (pos <= *max_width)
				pos++;
			*max_width += 2;
			line++;
		}
		if (floor > 2)
			*max_width += (floor % 2 ? (floor - 1) * 2 : (floor - 2) * 2);
		else
			*max_width += 2;
		floor++;
	}
}

void	display_line(int size, int floor, int line, int *max_pos, int max_width)
{
	int		pos;
	int		ind;

	pos = 1;
	ind = 1;
	while (ind++ < (max_width / 2) - (*max_pos / 2) - floor + 1)
		ft_putchar(' ');
	ft_putchar('/');
	while (pos <= *max_pos + (floor - 2) * 2)
	{
//		if (floor == size && (floor % 2 ? line > 2 : line > 3)
//				&& pos > (*max_pos + (*max_pos % 2)) / 2
//				&& pos < (*max_pos + (*max_pos % 2)) / 2 + floor)
//			ft_putchar('|');
//		else
			ft_putchar('*');
		pos++;
	}
	ft_putchar('\\');
	*max_pos += 2;
}

void	display_floor(int size, int floor, int *max_pos, int max_width)
{
	int		line;

	line = 1;
	while (line <= floor + 2)
	{
		display_line(size, floor, line, max_pos, max_width);
		ft_putchar('\n');
		line++;
	}
}

void	sastantua(int size)
{
	int		floor;
	int		max_pos;
	int		*p_max_pos;
	int		max_width;
	int		*p_max_width;

	floor = 1;
	max_pos = 3;
	p_max_pos = &max_pos;
	max_width = 3;
	p_max_width = &max_width;
	fake_pos(size, floor, p_max_width);
	while (floor <= size)
	{
		display_floor(size, floor, p_max_pos, max_width);
		if (floor > 2)
			max_pos += (floor % 2 ? (floor - 1) * 2 : (floor - 2) * 2);
		else
			max_pos += 2;
		floor++;
	}
}

#include <stdlib.h>

int		main(int ac, char **av)
{
	sastantua(atoi(av[1]));
}
