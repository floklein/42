/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:28:39 by flklein           #+#    #+#             */
/*   Updated: 2018/08/27 22:34:54 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int i)
{
	ft_putchar(i < 0 ? 'N' : 'P');
}

int		main()
{
ft_is_negative(-1);
ft_is_negative(0);
ft_is_negative(2);
}
