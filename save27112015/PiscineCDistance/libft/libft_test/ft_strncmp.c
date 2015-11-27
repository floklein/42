/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:44:37 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/08 18:17:21 by nsavry           ###   ########.fr       */
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
