/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:17:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 02:12:17 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp_sp(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] == ' ')
		i++;
	while (s1[i] && s2[j] && s1[i] != ' '
			&& (s1[i] == s2[j]
				|| s1[i] == s2[j] + 32 || s1[i] == s2[j] - 32))
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int		main(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp_sp(av[i], "president") == 0
				|| ft_strcmp_sp(av[i], "attack") == 0
				|| ft_strcmp_sp(av[i], "bauer") == 0
				|| ft_strcmp_sp(av[i], "president") == 32
				|| ft_strcmp_sp(av[i], "attack") == 32
				|| ft_strcmp_sp(av[i], "bauer") == 32
				|| ft_strcmp_sp(av[i], "president") == -32
				|| ft_strcmp_sp(av[i], "attack") == -32
				|| ft_strcmp_sp(av[i], "bauer") == -32)
		{
			write(1, "Alert!!!\n", 9);
			return (ac);
		}
		i++;
	}
	return (0);
}
