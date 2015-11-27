/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 21:39:30 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/13 21:39:32 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

void	ft_error(char *str, int err)
{
	if (err == 0)
		ft_printf("%s: Error\nUsage: %s <addr> <port>\n", str, str);
	else if (err == 1)
		ft_printf("%s: Error\nConnect error\n", str);
	exit(-1);
}
