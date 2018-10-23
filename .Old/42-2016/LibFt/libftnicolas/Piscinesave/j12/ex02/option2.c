/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:36:48 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:45:30 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	case_one(char **av, int *plus, int *bytes_nb, int *i)
{
	if (check_arg(av[*i], plus) == 0)
	{
		*bytes_nb = char_to_int(av[*i]);
		return (0);
	}
	else
		return (-1);
}

int	case_two(char **av, int *plus, int *bytes_nb, int *i)
{
	if (av[*i + 1] == '\0')
		return (-2);
	if (check_next_arg(av[*i + 1], plus) == 0)
	{
		*bytes_nb = char_to_int(av[*i + 1]);
		return (0);
	}
	else
		return (-1);
}

int	other_option(char **av, int i)
{
	if (av[i][0] == '-' && av[i][1] != '\0')
	{
		if ((av[i][1] != 'c' && av[i][1] != '-') &&
		(av[i - 1][0] != '-' && av[i - 1][1] != 'c'))
		{
			ft_putstr_stderr("tail : invalid option -- '");
			ft_putchar_stderr(av[i][1]);
			ft_putstr_stderr("'\n");
			return (-1);
		}
		if (av[i][1] == '-')
		{
			ft_putstr_stderr("tail : unknow option « ");
			ft_putstr_stderr(av[i]);
			ft_putstr_stderr(" »\n");
			return (-1);
		}
	}
	return (0);
}
