/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <fklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:05:47 by fklein            #+#    #+#             */
/*   Updated: 2016/11/14 19:31:25 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <stdio.h>

int		ft_prinft(const char *format);
void	ft_check_ident(int *nb, const char *format, int i, va_list ap);
int		ft_putchari(char c);
int		ft_putstri(char *str);
int		putnbri(int i);
int		ft_putnbrui(unsigned int i);
int		ft_putnbroi(unsigned int i);
int		ft_putnbrxi(unsigned int i);
int		ft_putnbrmxi(unsigned int i);
int		ft_putpti(long unsigned int i);

#endif
