/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:46:10 by fklein            #+#    #+#             */
/*   Updated: 2017/12/19 11:28:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fractal;

	if (argc != 2)
		return (errors(1));
	fractal = 1;
	fractol(fractal);
	return (0);
}
