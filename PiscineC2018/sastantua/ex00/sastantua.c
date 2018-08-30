/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:49:59 by flklein           #+#    #+#             */
/*   Updated: 2018/08/30 12:29:16 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_line(int floor, int line)
{
	int		pos;

	pos = 1;
	while (pos <= floor * (floor + 1) + line * 2)
	{
		ft_putchar('o');
		pos++;
	}
}

void	display_floor(int floor)
{
	int		line;

	line = 1;
	while (line <= floor + 2)
	{
		display_line(floor, line);
		ft_putchar('\n');
		line++;
	}
}

void	sastantua(int size)
{
	int		floor;

	floor = 1;
	while (floor <= size)
	{
		display_floor(floor);
		floor++;
	}
}

#include <stdlib.h>

int		main(int ac, char **av)
{
	sastantua(atoi(av[1]));
}
