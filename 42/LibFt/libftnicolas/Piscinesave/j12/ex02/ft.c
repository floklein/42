/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:34:56 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:43:47 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_arg(char *av)
{
	int	i;

	i = 2;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_next_arg(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '\0')
	{
		printf("option need an arg\n");
		return (-1);
	}
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	char_to_int(char *av)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (av[i] == '-' || av[i] == 'c')
		i++;
	while (av[i] != '\0')
	{
		nb = nb * 10 + (av[i] - 48);
		i++;
	}
	return (nb);
}

int	option(int *bytes_nb, int ac, char **av)
{
	int	i;

	i = 0;
	while (i++ < ac)
	{
		if (av[i][0] == '-' && av[i][1] == 'c')
		{
			if (av[i][2] != '\0')
			{
				if (check_arg(av[i]) == 0)
					*bytes_nb = char_to_int(av[i]);
				else
					return (-1);
			}
			else
			{
				if (check_next_arg(av[i + 1]) == 0)
					*bytes_nb = char_to_int(av[i + 1]);
				else
					return (-1);
			}
		}
	}
	return (1);
}
