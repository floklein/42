/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:49:59 by flklein           #+#    #+#             */
/*   Updated: 2018/08/30 15:04:43 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_line(int floor, int line, int *max_pos)
{
	int		pos;

	pos = 1;
	while (pos <= *max_pos)
	{
		ft_putchar('o');
		pos++;
	}
	*max_pos += 2;
}

void	display_floor(int floor, int *max_pos)
{
	int		line;

	line = 1;
	while (line <= floor + 2)
	{
		display_line(floor, line, max_pos);
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
		display_floor(floor, p_max_pos);
		max_pos += (floor % 2 ? (floor - 1) * 2 : (floor - 2) * 2);
		floor++;
	}
}

#include <stdlib.h>

int		main(int ac, char **av)
{
	sastantua(atoi(av[1]));
}
