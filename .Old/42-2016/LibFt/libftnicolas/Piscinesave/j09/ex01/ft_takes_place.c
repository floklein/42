/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:09:57 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/23 00:01:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	char	r;
	int		a;
	int		b;
	int		c;

	c = 1;
	a = hour;
	b = a + 1;
	r = '\n';
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 24)
		printf("%d.00 A.M. AND %d.00 A.M.%c", a, c, r);
	if (hour >= 1 && hour < 11)
		printf("%d.00 A.M. AND %d.00 A.M.%c", a, b, r);
	if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.%c", a, b, r);
	if (hour >= 12 && hour < 23)
		printf("%d.00 P.M. AND %d.00 P.M.%c", a, b, r);
	if (hour == 23)
		printf("%d.00 P.M. AND %d.00 A.M.%c", a, b, r);
}
