/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 19:01:29 by fklein            #+#    #+#             */
/*   Updated: 2015/10/19 11:31:21 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int i;

	i = '0';
	while (i <= '9')
	{
		ft_putchar(i);
		i++;
	}
	ft_putchar('\n');
}