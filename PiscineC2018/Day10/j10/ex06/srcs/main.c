/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:31:06 by flklein           #+#    #+#             */
/*   Updated: 2018/09/10 23:11:32 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_str_is_operator(char *str)
{
	int		i;

	if (ft_strlen(str) != 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
				&& str[i] != '%')
			return (0);
		i++;
	}
	return (1);
}

int		define_op(char *operator)
{
	char	all_ops[6];

	ft_strcpy(all_ops, "+-*/%\0");
	return (ft_strstr(all_ops, operator) - all_ops);
}

int		main(int ac, char **av)
{
	int		nb1;
	int		nb2;
	int		op;
	int		(*operation[5])(int, int);

	if (ac != 4)
		return (0);
	if (!ft_str_is_operator(av[2]))
		return (ft_putstr("0\n"));
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	op = define_op(av[2]);
	if (nb2 == 0 && (op == 3 || op == 4))
	{
		ft_putstr("Stop : ");
		return (ft_putstr(op == 3 ? "division by zero\n" : "modulo by zero\n"));
	}
	operation[0] = ft_add;
	operation[1] = ft_sub;
	operation[2] = ft_mult;
	operation[3] = ft_div;
	operation[4] = ft_mod;
	ft_putnbr((*operation[op])(nb1, nb2));
	ft_putstr("\n");
	return (0);
}
