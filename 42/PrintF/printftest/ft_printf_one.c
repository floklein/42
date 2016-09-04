/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:03:46 by fklein            #+#    #+#             */
/*   Updated: 2016/07/25 16:21:39 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_check_ident(int *nb, const char *format, int i, va_list ap)
{
	if (format[i] == 's')
		*nb += ft_putstri(va_arg(ap, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		*nb += ft_putnbri(va_arg(ap, int));
	else if (format[i] == 'c')
		*nb += ft_putchari(va_arg(ap, int));
	else if (format[i] == 'u')
		*nb += ft_putnbrui(va_arg(ap, unsigned int));
	else if (format[i] == 'o')
		*nb += ft_putnbroi(va_arg(ap, unsigned int));
	else if (format[i] == 'x')
		*nb += ft_putnbrxi(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		*nb += ft_putnbrmxi(va_arg(ap, unsigned int));
	else if (format[i] == 'p')
		*nb += ft_putpti(va_arg(ap, long unsigned int));
	else if (format[i] == '%')
		*nb += ft_putchari('%');
}

static int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			nb;

	nb = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_ident(&nb, format, i, ap);
		}
		else
			nb += ft_putchari(format[i]);
		i++;
	}
	return (nb);
}
