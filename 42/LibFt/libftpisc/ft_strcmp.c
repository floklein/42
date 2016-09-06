/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:07:06 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:07:08 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i])
		i++;
	if (str1[i] < str2[i])
		result = -1;
	else if (str1[i] > str2[i])
		result = 1;
	else
		result = 0;
	return (result);
}
