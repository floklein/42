/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:07:02 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 11:35:15 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if ((s2 = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1)))) == NULL)
		return (NULL);
	i = 0;
	while ((*(s2 + i) = *(s1 + i)) != '\0')
		i++;
	return (s2);
}
