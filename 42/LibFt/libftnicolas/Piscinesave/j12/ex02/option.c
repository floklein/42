/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:36:39 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 18:32:35 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_arg(char *av, int *plus)
{
	int	i;

	i = 2;
	while (av[i] != '\0')
	{
		if (av[i] == '+')
		{
			if (av[i + 1] == '\0')
				return (-1);
			*plus = *plus + 1;
			i++;
		}
		else if (av[i] == '-')
		{
			if (av[i + 1] == '\0')
				return (-1);
			i++;
		}
		while (av[i] >= '0' && av[i] <= '9')
			i++;
		if (av[i] != '\0')
			return (-1);
	}
	return (0);
}

int	check_next_arg(char *av, int *plus)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '+')
		{
			if (av[i + 1] == '\0')
				return (-1);
			*plus = *plus + 1;
			i++;
		}
		else if (av[i] == '-')
		{
			if (av[i + 1] == '\0')
				return (-1);
			i++;
		}
		while (av[i] >= '0' && av[i] <= '9')
			i++;
		if (av[i] != '\0')
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
	while (av[i] == '-' || av[i] == 'c' || av[i] == '+')
		i++;
	while (av[i] != '\0')
	{
		nb = nb * 10 + (av[i] - 48);
		i++;
	}
	return (nb);
}

int	get_bytes_nb(char **av, int *plus, int *bytes_nb, int *i)
{
	if (av[*i][0] == '-' && av[*i][1] == 'c')
	{
		if (av[*i][2] != '\0')
		{
			if (case_one(av, plus, bytes_nb, i) == -1)
			{
				display_error(av[*i], 1);
				return (-1);
			}
		}
		else
		{
			if (case_two(av, plus, bytes_nb, i) == -1)
			{
				display_error(av[*i + 1], 2);
				return (-1);
			}
			else if (case_two(av, plus, bytes_nb, i) == -2)
			{
				display_error(av[*i], 3);
				return (-1);
			}
		}
	}
	return (0);
}

int	option(int *bytes_nb, int ac, char **av)
{
	int	i;
	int	plus;
	int	ret;

	i = 1;
	plus = 0;
	while (i < ac)
	{
		if (other_option(av, i) < 0)
			return (-1);
		ret = get_bytes_nb(av, &plus, bytes_nb, &i);
		if (ret < 0)
			return (ret);
		i++;
	}
	return (plus);
}
