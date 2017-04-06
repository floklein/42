/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:09:47 by fklein            #+#    #+#             */
/*   Updated: 2016/03/21 14:09:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_solvestr(const char *str, const char *seek)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (str[i1] != 0)
	{
		while (str[i1] == seek[i2])
		{
			i1++;
			i2++;
			if (seek[i2] == 0)
				return (1);
		}
		i2 = 0;
		i1++;
	}
	return (0);
}

int			ft_strstr_bool(const char *str, const char *seek)
{
	if (!(*seek))
		return (0);
	else
		return (ft_solvestr(str, seek));
}
