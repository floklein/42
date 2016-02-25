/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:52:06 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/06 00:38:29 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (size == 0)
		return (NULL);
	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	while (size)
		s[size--] = '\0';
	*s = '\0';
	return (s);
}
