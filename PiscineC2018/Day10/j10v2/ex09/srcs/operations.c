/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:44:51 by flklein           #+#    #+#             */
/*   Updated: 2018/09/11 14:30:29 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_add(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int		ft_sub(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int		ft_mul(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int		ft_div(int nb1, int nb2)
{
	return (nb1 / nb2);
}

int		ft_mod(int nb1, int nb2)
{
	return (nb1 % nb2);
}
