/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:22:38 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 14:22:40 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	return (ft_strcpy(s, str));
}
