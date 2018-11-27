/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:41 by flklein           #+#    #+#             */
/*   Updated: 2018/11/27 18:47:44 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, void *mlx)
{
	ft_putstr("pressed: ");
	ft_putnbr(key);
	ft_putchar('\n');
	(void)mlx;
	if (key == 53)
		exit(0);
	return (0);
}
