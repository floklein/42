/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 01:09:26 by flklein           #+#    #+#             */
/*   Updated: 2018/08/31 11:35:55 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (i++ < ac - 1)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
	return (0);
}
