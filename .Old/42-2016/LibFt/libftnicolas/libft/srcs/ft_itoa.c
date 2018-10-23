/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:18:37 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/23 15:03:22 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	length(int *n, int *pos_neg)
{
	int	len;
	int	tmp;

	len = 0;
	if (*n < 0)
	{
		*pos_neg = -1;
		*n = *n * *pos_neg;
		len++;
	}
	tmp = *n;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	if (*n == 0)
		len++;
	return (len);
}

static char	*do_itoa(int len, int pos_neg, int n)
{
	char	*str;

	str = NULL;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (str);
	str[len] = '\0';
	len--;
	while (n > 9)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[len] = n + 48;
	len--;
	if (pos_neg == -1)
		str[len] = '-';
	return (str);
}

static void	tab_init(char *limit)
{
	limit[0] = '-';
	limit[1] = '2';
	limit[2] = '1';
	limit[3] = '4';
	limit[4] = '7';
	limit[5] = '4';
	limit[6] = '8';
	limit[7] = '3';
	limit[8] = '6';
	limit[9] = '4';
	limit[10] = '8';
	limit[11] = '\0';
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		pos_neg;
	char	limit[12];

	tab_init(limit);
	if (n != -2147483648)
	{
		len = 0;
		pos_neg = 1;
		len = length(&n, &pos_neg);
		str = do_itoa(len, pos_neg, n);
	}
	else
	{
		if ((str = (char *)malloc(sizeof(char) * 12)) == NULL)
			return (NULL);
		str = ft_strcpy(str, limit);
	}
	return (str);
}
