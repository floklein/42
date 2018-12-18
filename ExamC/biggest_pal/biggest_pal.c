/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:01:52 by exam              #+#    #+#             */
/*   Updated: 2018/12/18 12:23:34 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		is_pal(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (str[i] != str[len])
			return (0);
		i++;
		len--;
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	*str;
	int		i;
	int		len;
	char	*pal;
	int		len_pal;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	len_pal = 0;
	i = 0;
	while (str[i])
	{
		len = ft_strlen(str + i);
		while (len >= len_pal)
		{
			if (is_pal(str + i, len - 1) && len >= len_pal)
			{
				pal = str + i;
				len_pal = len;
			}
			len--;
		}
		i++;
	}
	write(1, pal, len_pal);
	write(1, "\n", 1);
	return (0);
}
