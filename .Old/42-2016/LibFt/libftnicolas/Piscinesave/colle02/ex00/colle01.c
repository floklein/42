/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 13:01:02 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/17 13:38:57 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_begin(int x)
{
	int count_x;

	count_x = 1;
	while (count_x <= x)
	{
		if (count_x == 1)
		{
			ft_putchar('/');
		}
		else if (count_x == x)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		count_x++;
	}
}

void	ft_print_end(int x)
{
	int count_x;

	count_x = 1;
	while (count_x <= x)
	{
		if (count_x == 1)
		{
			ft_putchar('\\');
		}
		else if (count_x == x)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
		count_x++;
	}
}

void	ft_print_empty_line(int x)
{
	int count_x;

	count_x = 1;
	while (count_x <= x)
	{
		if (count_x == 1 || count_x == x)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
		count_x++;
	}
}

void	colle(int x, int y)
{
	int count_y;

	count_y = 1;
	while (count_y <= y)
	{
		if (count_y == 1)
		{
			ft_print_begin(x);
		}
		else if (count_y == y)
		{
			ft_print_end(x);
		}
		else
		{
			ft_print_empty_line(x);
		}
		if (x > 0)
			ft_putchar('\n');
		count_y++;
	}
}
