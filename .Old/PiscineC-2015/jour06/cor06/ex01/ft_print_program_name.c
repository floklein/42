/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 15:48:47 by fklein            #+#    #+#             */
/*   Updated: 2015/10/28 19:44:31 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*(str++))
		ft_putchar(*(str - 1));
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr(argv[0]);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr(argv[0]);
		ft_putchar('\n');
	}
	return (0);
}
