/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 21:40:08 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/13 21:40:09 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	ft_error(char *str, int err)
{
	if (err == 0)
		ft_printf("%s: Error\nUsage: %s <port>\n", str, str);
	else if (err == 1)
		ft_printf("%s: Error\nPort already used\n", str);
	exit(-1);
}
