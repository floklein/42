/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:44:13 by flklein           #+#    #+#             */
/*   Updated: 2018/09/06 17:51:17 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		h;

	if (hour < 12)
		h = hour;
	else if (hour < 24)
		h = hour - 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 12)
		printf("12.00 P.M. AND 1.00 P.M.\n");
	else if (hour == 24 || hour == 0)
		printf("12.00 A.M. AND 1.00 A.M.\n");
	else if (hour == 11)
		printf("11.00 A.M. AND 12.00 P.M.\n");
	else if (hour == 23)
		printf("11.00 P.M. AND 12.00 A.M.\n");
	else if (hour < 11)
		printf("%d.00 A.M. AND %d.00 A.M.\n", h, h + 1);
	else if (hour < 23)
		printf("%d.00 P.M. AND %d.00 P.M.\n", h, h + 1);
}
