/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 02:09:36 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 15:25:52 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_make_tree.h"

int		eval_expr(char *str)
{
	t_node	*node;
	int		res;
	char	*exp;

	exp = ft_dead_space(str);
	node = make_tree(exp);
	res = ft_calc_tree(node);
	return (res);
	ft_deforestation(node);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
