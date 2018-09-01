/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:49:59 by flklein           #+#    #+#             */
/*   Updated: 2018/08/30 20:08:10 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_width(int size)
{
	int		floor_add_m;
	int		max_char;
	int		floor_m;

	max_char = 7;
	floor_add_m = 2;
	floor_m = 2;
	while (floor_m <= size)
	{
		max_char += ((floor_m + 2) * 2);
		if (floor_m % 2 == 0)
			floor_add_m += 2;
		floor_m++;
		max_char += floor_add_m;
	}
	return (max_char);
}

void	display_line(int size, int floor, int line, int *max_pos)
{
	int		pos;
	int		ind;
	int		max_width;

	pos = 1;
	ind = 0;
	max_width = find_width(size);
	while (ind++ < (max_width / 2) - (*max_pos / 2) - floor - 1)
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

void	display_floor(int size, int floor, int *max_pos)
{
	int		line;

	line = 1;
	while (line <= floor + 2)
	{
		display_line(size, floor, line, max_pos);
		ft_putchar('\n');
		line++;
	}
}

void	sastantua(int size)
{
	int		floor;
	int		max_pos;
	int		*p_max_pos;

	floor = 1;
	max_pos = 3;
	p_max_pos = &max_pos;
	while (floor <= size)
	{
		display_floor(size, floor, p_max_pos);
			max_pos += 2;
		floor++;
	}
}

#include <stdlib.h>

int		main(int ac, char **av)
{
	sastantua(atoi(av[1]));
}
