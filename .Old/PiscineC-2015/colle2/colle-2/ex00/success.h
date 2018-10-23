/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 01:30:58 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 01:32:05 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUCCESS_H
# define SUCCESS_H
# include <unistd.h>
# include <stdlib.h>

void	display(char *colle, int x, int y);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
