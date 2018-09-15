/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:11:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/15 19:25:44 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		define_op(char oper, t_opp *g_opptab)
{
	int		op;

	op = 0;
	while (op < 5)
	{
		if (oper == g_opptab[op].operand)
			return (op);
		op++;
	}
	return (op);
}

int		do_op(int nb1, int nb2, char oper)
{
	t_opp	g_opptab[5];
	int		res;
	int		op;

/*	g_opptab[0] = {'+', &ft_add};
	g_opptab[1] = {'-', &ft_sub};
	g_opptab[2] = {'*', &ft_mul};
	g_opptab[3] = {'/', &ft_div};
	g_opptab[4] = {'%', &ft_mod};*/
	op = define_op(oper, g_opptab);
	res = (g_opptab[op].operation)(nb1, nb2);
	return (0);
}
