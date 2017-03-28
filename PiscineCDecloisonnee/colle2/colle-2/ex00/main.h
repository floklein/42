/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 20:57:57 by fklein            #+#    #+#             */
/*   Updated: 2015/11/01 20:00:30 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <stdlib.h>

char	*colle0(int x, int y);
char	*colle1(int x, int y);
char	*colle2(int x, int y);
char	*colle3(int x, int y);
char	*colle4(int x, int y);
void	display(char *colle, int x, int y);
int		ft_strcmp(char *str1, char *str2);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		success1(int what_else, int x, int y);
int		success2(int what_else, int x, int y);
int		success3(int what_else, int x, int y);
int		success4(int what_else, int x, int y);
int		successcarre(int what_else, int x, int y);

#endif
