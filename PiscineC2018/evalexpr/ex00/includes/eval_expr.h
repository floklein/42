/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:00:14 by flklein           #+#    #+#             */
/*   Updated: 2018/09/15 19:23:10 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_opp
{
	char	operand;
	int		(*operation)(int, int);
}				t_opp;

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		do_op(int nb1, int nb2, char oper);
char	**parse_str(char *str);

#endif
