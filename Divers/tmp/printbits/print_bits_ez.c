/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits_ez.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:46:40 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 14:49:33 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_bits(unsigned char octet)
{
	int		i;

	i = 128;
	while (i > 0)
	{
		if ((octet & i))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

int		main(void)
{
	ft_print_bits(13);
}
