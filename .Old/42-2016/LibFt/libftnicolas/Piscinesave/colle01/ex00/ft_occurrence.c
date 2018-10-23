/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurrence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 19:15:45 by thifranc          #+#    #+#             */
/*   Updated: 2015/10/25 21:27:30 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_line_occ(char c, char *str, int x)
{
	x += 1;
	while (x <= 8)
	{
		if (str[x] == c)
			return (1);
		x++;
	}
	return (0);
}

int	ft_col_occ(char c, char **tab, int x, int y)
{
	y += 1;
	while (y <= 9)
	{
		if (tab[y][x] == c)
			return (1);
		y++;
	}
	return (0);
}

int	ft_bloc_occ(char **tab, int x, int y)
{
	int xb;
	int yb;
	int limx;
	int limy;

	if (y <= 3)
		yb = 1;
	else if (y <= 6)
		yb = 4;
	else
		yb = 7;
	limy = yb + 2;
	while (yb <= limy)
	{
		xb = x - x % 3;
		limx = xb + 2;
		while (xb <= limx)
		{
			if (tab[yb][xb] == tab[y][x] && xb != x && yb != y)
				return (1);
			xb++;
		}
		yb++;
	}
	return (0);
}
