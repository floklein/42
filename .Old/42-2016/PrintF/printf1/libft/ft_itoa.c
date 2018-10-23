/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:01:58 by fklein            #+#    #+#             */
/*   Updated: 2016/07/27 16:04:29 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_special(char *str, int n)
{
	const char	special[12] = "-2147483648";

	if (n == 0)
	{
		if ((str = (char *)malloc(sizeof(*str) * (2))) == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (n == -2147483648)
	{
		if ((str = (char *)malloc(sizeof(*str) * 13)) == NULL)
			return (NULL);
		str = ft_strcpy(str, special);
	}
	return (str);
}

static char	*ft_solve(char *str, int len, int n, int realn)
{
	int		temp;

	temp = n;
	while (temp != 0)
	{
		len++;
		temp = temp / 10;
	}
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	str[len] = 0;
	while (n != 0)
	{
		len--;
		str[len] = ((n % 10) + 48);
		n = n / 10;
	}
	if (realn < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		realn;

	realn = n;
	str = NULL;
	len = 0;
	if (n == 0 || n == -2147483648)
	{
		str = ft_special(str, n);
		return (str);
	}
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	str = ft_solve(str, len, n, realn);
	return (str);
}
