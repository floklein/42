/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:13:18 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/18 18:14:16 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		add(int op1, int op2);
int		sub(int op1, int op2);
int		mul(int op1, int op2);
int		div(int op1, int op2);
int		mod(int op1, int op2);
int		do_op(char **argv);
int		what_operator(char **argv);
void	set_funptrtab(int (**funptrtab)(int, int));
int		get_operand(char *tab);
int		check(int operator, int operand);
#endif
