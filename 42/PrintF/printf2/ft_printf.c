/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:59:47 by fklein            #+#    #+#             */
/*   Updated: 2017/03/30 12:14:43 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

int		valid_spec(char c)
{
	return (c == 's' || c == 'S'
		|| c == 'p'
		|| c == 'd' || c == 'D'
		|| c == 'i'
		|| c == 'o' || c == 'O'
		|| c == 'u' || c == 'U'
		|| c == 'x' || c == 'X'
		|| c == 'c' || c == 'C'
		|| c == '%')
}

int		parser(char *str, void *arg)
{
	int			conv_length;
	t_conv		conv_struct;

	while (!valid_spec(str[i]))
	{
		if
		i++;
	}

//	set le specifier
//	printer la struct
	return (conv_length);
}

int		ft_printf(const char *format, ...)
{
	int			i;
	static int	written;
	va_list		params;

	i = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] != '%')
			written += write(1, format + i, 1);
		else
			i += parser(format + i + 1, va_arg(params, void*));
		i++;
	}
	return (i);
}

int		main(void)
{
	ft_printf("salut\n");
}
