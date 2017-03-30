/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:10:03 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:10:08 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsubin(char *str, int i, int j)
{
	char	*new;
	char	*tmp;
	int		len;

	len = ft_strlen(str) - j + i;
	new = malloc(sizeof(char) * (len + 1));
	new = ft_strncpy(new, str, i);
	tmp = new + i;
	tmp = ft_strcpy(tmp, str + j);
	new[len] = 0;
	return (new);
}
