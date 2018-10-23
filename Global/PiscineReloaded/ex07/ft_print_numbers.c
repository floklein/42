/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:40:13 by flklein           #+#    #+#             */
/*   Updated: 2018/10/23 20:40:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c){write(1, &c, 1);}

void	ft_print_numbers(void)
{
	int	c;

	c = '0';
	while (c <= '9')
		ft_putchar(c++);
}

int	main(void)
{
	ft_print_numbers();
}
