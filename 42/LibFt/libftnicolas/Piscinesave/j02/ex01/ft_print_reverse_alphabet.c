/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 15:34:48 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/21 19:30:27 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char	actual_letter;
	char	last_letter;

	actual_letter = 'z';
	last_letter = 'a';
	while (actual_letter >= last_letter)
	{
		ft_putchar(actual_letter);
		actual_letter--;
	}
}
