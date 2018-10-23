/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:02:32 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/18 20:19:34 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	res;
	int	count1;
	int	count2;

	i = 0;
	j = 1;
	res = 0;
	count1 = 0;
	count2 = 0;
	if (length == 0 || length == 1)
		return (1);
	while (j < length)
	{
		res = f(tab[i++], tab[j++]);
		if (res > 0)
			count1++;
		if (res < 0)
			count2++;
	}
	if ((count1 == 0 && count2 > 0) || (count2 == 0 && count1 > 0))
		return (1);
	else
		return (0);
}
