/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:29:11 by flklein           #+#    #+#             */
/*   Updated: 2018/09/07 13:59:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_bits(unsigned char oct)
{
	int		octet;

	octet = (int)oct;
	while (octet > 0)
	{
		if ((octet & 1) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet >>= 1;
	}
}

int		main(void)
{
	print_bits(2);
}
