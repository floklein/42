/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 17:05:39 by fklein            #+#    #+#             */
/*   Updated: 2015/10/18 23:29:45 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putchar(char c);

int		ft_max_size(int size_m)
{
	int floor_add_m;
	int max_char;
	int floor_m;

	max_char = 7;
	floor_add_m = 2;
	floor_m = 2;
	while (floor_m <= size_m)
	{
		max_char += ((floor_m + 2) * 2);
		if (floor_m % 2 == 0)
			floor_add_m += 2;
		floor_m++;
		max_char += floor_add_m;
	}
	return (max_char);
}

void	print_line(int floor, int size, int line_f, int size_line)
{
	int width;
	int pos_l;

	pos_l = 0;
	while (pos_l++ < (ft_max_size(size) / 2) - (size_line / 2) - 1)
		ft_putchar(' ');
	ft_putchar('/');
	while (pos_l <= size_line / 2 + ft_max_size(size) / 2)
	{
		width = (size - 1) / 2;
		if (floor == size && line_f > 3 - size % 2 &&
		(pos_l >= ft_max_size(size) / 2 - width &&
		pos_l <= ft_max_size(size) / 2 + width))
			if (line_f == 4 + width - size % 2
			&& pos_l == ft_max_size(size) / 2 + width - 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		else
			ft_putchar('*');
		pos_l++;
	}
}

int		print_floor(int size, int floor, int line_f, int size_line)
{
	while (line_f++ < floor + 2)
	{
		print_line(floor, size, line_f, size_line);
		ft_putchar('\\');
		ft_putchar('\n');
		size_line += 2;
	}
	return (size_line);
}

void	ft_sastantua(int size)
{
	int floor;
	int line_f;
	int size_line;
	int floor_add;

	floor = 1;
	size_line = 0;
	floor_add = 4;
	while (floor <= size)
	{
		line_f = 0;
		if (floor % 2 == 0 && floor != 2)
			floor_add += 2;
		if (floor != 1)
			size_line += floor_add;
		size_line = print_floor(size, floor, line_f, size_line);
		floor++;
	}
}
