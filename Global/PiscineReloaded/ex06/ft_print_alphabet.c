/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <flklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:28:37 by flklein           #+#    #+#             */
/*   Updated: 2018/10/23 19:57:26 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c){write(1, &c, 1);}

void	ft_print_alphabet(void)
{
	int	c;

	c = 'a';
	while (c <= 'z')
		ft_putchar(c++);
}

int	main(void)
{
	ft_print_alphabet();
}
