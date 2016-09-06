/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 15:33:08 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/21 19:28:57 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	actual_letter;
	char	last_letter;

	actual_letter = 'a';
	last_letter = 'z';
	while (actual_letter <= last_letter)
	{
		ft_putchar(actual_letter);
		actual_letter++;
	}
}
