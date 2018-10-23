/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:31:17 by fklein            #+#    #+#             */
/*   Updated: 2017/12/19 11:28:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

int	errors(int number)
{
	if (number == 1)
		ft_putstr_fd("Usage: ./fractol <fractal name>\n", 2);
	return (0);
}
