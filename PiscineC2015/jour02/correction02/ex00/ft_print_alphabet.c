/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 19:01:29 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 14:54:50 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void);
int main()
{
	char i;

	i = 'a';
	while (i <= 'z')
	{
		ft_putchar(i);
		i++;
	}
	ft_putchar('\n');
}
