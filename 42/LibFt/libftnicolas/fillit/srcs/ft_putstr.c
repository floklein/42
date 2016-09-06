/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsmite <dwight.smite@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:53:38 by dsmite            #+#    #+#             */
/*   Updated: 2016/05/01 08:53:31 by dsmite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_putstr(const char *s)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		ft_putchar((char)*(s + i));
		i++;
	}
}

void	ft_putstr_stderr(const char *s)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		ft_putchar_stderr((char)*(s + i));
		i++;
	}
}
