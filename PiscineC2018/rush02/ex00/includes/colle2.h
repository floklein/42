/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle-2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:36:10 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 01:45:20 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE2_H
# define COLLE2_H

# define BUF_SIZE 10

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strjoin(char *str1, char *str2);
void	ft_putnbr(int nb);
void	rush_comp(char *input);
char	*rush_00(int x, int y);
char	*rush_01(int x, int y);
char	*rush_02(int x, int y);
char	*rush_03(int x, int y);
char	*rush_04(int x, int y);

#endif
