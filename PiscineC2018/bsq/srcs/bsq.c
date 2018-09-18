/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:05:16 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 19:57:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

void	display_bsq(t_params *par)
{
	int		a;
	int		b;

	printf("imax:%d - jmax:%d\n - x:%c\n", par->max_i, par->max_j, par->x);
	a = par->max_i - par->max;
	while (a < par->max_i)
	{
		b = par->max_j - par->max;
		while (b < par->max_j)
		{
			printf("a:%d - b:%d\n", a, b);
			par->map[a * (par->columns + 1) + b] = par->x;
			b++;
		}
		a++;
	}
	write(1, (par->map), ft_strlen(par->map));
}
