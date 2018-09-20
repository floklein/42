/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:43:33 by flklein           #+#    #+#             */
/*   Updated: 2018/09/10 16:15:18 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*cpy;
	int		i;

	if (!(cpy = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		cpy[i] = (*f)(tab[i]);
		i++;
	}
	return (cpy);
}

void	ft_putchar(char c)
{write(1, &c, 1);}

int		add_one(int nb)
{
	ft_putchar(nb + 1 + '0');
	return (nb + 1);
}

int		main(void)
{
	int		tab[3] = {1, 2, 3};

	ft_map(tab, 3, &add_one);
}
