/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:02:55 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/18 18:03:01 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	do_op(char **argv)
{
	int	(*funptrtab[5])(int, int);
	int	operator;
	int	operand1;
	int	operand2;

	operand1 = get_operand(argv[1]);
	operand2 = get_operand(argv[3]);
	set_funptrtab(funptrtab);
	operator = what_operator(argv);
	if (check(operator, operand2) != 0)
		return (0);
	ft_putnbr(funptrtab[operator](operand1, operand2));
	ft_putchar('\n');
	return (0);
}
