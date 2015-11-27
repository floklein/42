/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 22:49:52 by fklein            #+#    #+#             */
/*   Updated: 2015/11/05 23:44:49 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (tab[index])
	{
		if ((*f)(tab[index]) == 1)
			count++;
		index++;
	}
	return (count);
}
