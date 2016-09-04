/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 13:57:53 by fklein            #+#    #+#             */
/*   Updated: 2016/09/01 17:00:17 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
