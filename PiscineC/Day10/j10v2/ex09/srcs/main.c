/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:31:06 by flklein           #+#    #+#             */
/*   Updated: 2018/09/12 15:38:46 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "ft_opp.h"

int		ft_usage(int nb1, int nb2)
{
	int		i;

	ft_putstr("error : only [ ");
	i = 0;
	while (i < 5)
	{
		ft_putstr(g_opptab[i].operand);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("] are accepted.\n");
	return (nb1 || nb2);
}

int		define_op(char *oper)
{
	int		op;

	op = 0;
	while (op < 5)
	{
		if (ft_strcmp(oper, g_opptab[op].operand) == 0)
			return (op);
		op++;
	}
	return (op);
}

int		main(int ac, char **av)
{
	int		nb1;
	int		nb2;
	int		op;

	if (ac != 4)
		return (0);
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	op = define_op(av[2]);
	if (g_opptab[op].operation != &ft_usage)
	{
		if (g_opptab[op].operation == &ft_div && nb2 == 0)
			ft_putstr("Stop : division by zero");
		else if (g_opptab[op].operation == &ft_mod && nb2 == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr((g_opptab[op].operation)(nb1, nb2));
		ft_putstr("\n");
	}
	else
		g_opptab[op].operation(nb1, nb2);
	return (0);
}
