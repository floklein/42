/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:08:42 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:08:44 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while ((str1[i] == str2[i]) && str1[i] && str2[i] && (i < n))
		i++;
	if (str1[i] < str2[i])
		result = -1;
	else if (str1[i] > str2[i])
		result = 1;
	else if (str1[i] == str2[i])
		result = 0;
	return (result);
}
