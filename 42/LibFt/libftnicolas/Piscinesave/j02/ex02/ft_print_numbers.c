/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 15:35:31 by nthibaud          #+#    #+#             */
/*   Updated: 2015/10/21 19:31:37 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	actual_number;
	char	last_number;

	actual_number = '0';
	last_number = '9';
	while (actual_number <= last_number)
	{
		ft_putchar(actual_number);
		actual_number++;
	}
}
