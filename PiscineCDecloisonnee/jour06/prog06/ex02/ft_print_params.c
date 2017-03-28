/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 16:00:35 by fklein            #+#    #+#             */
/*   Updated: 2015/10/27 22:59:27 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}

int		main(int argc, char **argv)
{
	int index;

	index = 1;
	if (argc == 1)
		return (0);
	else
		while (index != argc)
		{
			ft_putstr(argv[index]);
			ft_putchar('\n');
			index++;
		}
	return (0);
}
