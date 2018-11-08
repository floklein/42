/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:44:07 by flklein           #+#    #+#             */
/*   Updated: 2018/11/08 12:45:11 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = (char *)s + i;
		i++;
	}
	if (s[i] == c)
		tmp = (char *)s + i;
	return (tmp);
}
