/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:03:32 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/19 12:22:09 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check(int operator, int operand)
{
	if (operator == -1)
	{
		ft_putstr("0\n");
		return (1);
	}
	if (operand == 0 && operator == 3)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (operand == 0 && operator == 4)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

int		get_operand(char *tab)
{
	int		i;
	int		operand;

	i = 0;
	operand = 0;
	if ((tab[i] < '0' || tab[i] > '9') && tab[i] != '-')
		return (0);
	if (tab[i] == '-' && (tab[i + 1] >= '0' && tab[i + 1] <= '9'))
		i++;
	while (tab[i] >= '0' && tab[i] <= '9')
	{
		if (tab[i + 1] >= '0' && tab[i + 1] <= '9')
			operand = (operand + (tab[i] - 48)) * 10;
		else
			operand = operand + (tab[i] - 48);
		i++;
	}
	if (tab[0] == '-')
		operand = operand * -1;
	return (operand);
}

void	set_funptrtab(int (**funptrtab)(int, int))
{
	funptrtab[0] = &add;
	funptrtab[1] = &sub;
	funptrtab[2] = &mul;
	funptrtab[3] = &div;
	funptrtab[4] = &mod;
}

int		what_operator(char **argv)
{
	int		i;
	char	operator_tab[5];

	i = 0;
	operator_tab[0] = '+';
	operator_tab[1] = '-';
	operator_tab[2] = '*';
	operator_tab[3] = '/';
	operator_tab[4] = '%';
	while (i <= 4)
	{
		if (argv[2][0] == operator_tab[i])
			return (i);
		i++;
	}
	return (-1);
}
