/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 18:21:07 by thifranc          #+#    #+#             */
/*   Updated: 2015/10/25 21:41:08 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_line_occ(char c, char *str, int x);

int ft_col_occ(char c, char **tab, int x, int y);

int ft_bloc_occ(char **tab, int x, int y);

int	ft_occ_test(char **tab, int x, int y)
{
	if (ft_line_occ(tab[y][x], tab[y], x) == 0
		&& ft_col_occ(tab[y][x], tab, x, y) == 0
		&& ft_bloc_occ(tab, x, y) == 0)
		return (1);
	return (0);
}

int	ft_char_test(char **tab)
{
	int x;
	int y;

	y = 1;
	while (y <= 9)
	{
		x = 0;
		while (x <= 8)
		{
			if (tab[y][x] != '.' && tab[y][x] < '1' && tab[y][x] > '9')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_size_test(char **tab)
{
	int x;
	int y;
	int count;

	y = 1;
	count = 0;
	while (++y <= 9)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] >= '1' && tab[y][x] <= '9')
			{
				count++;
				if (ft_occ_test(tab, x, y) == 0)
					return (0);
			}
			x++;
		}
		if (x > 9 || x < 8)
			return (0);
	}
	if (count < 17)
		return (0);
	return (1);
}
