/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:14:57 by fklein            #+#    #+#             */
/*   Updated: 2017/03/28 17:01:20 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	char			*s;
	S;
	p;
	int				d;
	D;
	int				i;
	unsigned int	o;
	O;
	unsigned int	u;
	U;
	unsigned int	x;
	unsigned int	X;
	char			c;
	C;

	printf("s = %s\n", s);
	ft_printf("s = %s\n", s);
//	printf("S = %s\n", S);
//	ft_printf("S = %S\n", S);
	printf("p = %p\n", p);
	ft_printf("p = %p\n", p);
	printf("d = %d\n", d);
	ft_printf("d = %d\n", d);
//	printf("D = %D\n", D);
//	ft_printf("D = %D\n", D);
//	printf("i = %i\n", i);
//	ft_printf("i = %i\n", i);
	printf("o = %o\n", o);
	ft_printf("o = %o\n", o);
//	printf("O = %O\n", O);
//	ft_printf("O = %O\n", O);
	printf("u = %u\n", u);
	ft_printf("u = %u\n", u);
//	printf("U = %U\n", U);
//	ft_printf("U = %U\n", U);
	printf("x = %x\n", x);
	ft_printf("x = %x\n", x);
	printf("X = %X\n", X);
	ft_printf("X = %X\n", X);
	printf("c = %c\n", c);
	ft_printf("c = %c\n", c);
//	printf("C = %C\n", C);
//	ft_printf("C = %C\n", C);
}
