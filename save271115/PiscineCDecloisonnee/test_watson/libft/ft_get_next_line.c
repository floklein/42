/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:37:40 by nsavry            #+#    #+#             */
/*   Updated: 2013/12/22 14:21:41 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int				ft_get_next_line(int fd, char **line)
{
	char	*tmp;
	char	c[2];
	int		r;

	(*line) = strdup("");
	c[1] = 0;
	while ((r = read(fd, c, 1)) > 0)
	{
		if (c[0] == '\n')
			return (1);
		tmp = (*line);
		(*line) = ft_strjoin(tmp, c);
		free(tmp);
	}
	if (r == 0)
		return (0);
	return (-1);
}
