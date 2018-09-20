/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:04:31 by flklein           #+#    #+#             */
/*   Updated: 2018/09/12 17:11:33 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char *))
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			count++;
		i++;
	}
	return (count);
}
