/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gardening.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 22:27:41 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 15:26:48 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_make_tree.h"

char	*ft_dead_space(char *str)
{
	int		i;
	char	*n_str;

	n_str = malloc(sizeof(*n_str) * (ft_strlen(str) + 1));
	i = 0;
	while (*str)
	{
		if (*str != ' ')
		{
			n_str[i] = *str;
			i++;
		}
		str++;
	}
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strip_pth(char *str)
{
	int		len;
	int		pth_lvl;

	len = ft_strlen(str) - 1;
	pth_lvl = 0;
	while (str[pth_lvl] == '(' && str[len - pth_lvl] == ')')
	{
		str[len - pth_lvl] = '\0';
		pth_lvl++;
	}
	return (&str[pth_lvl]);
}
