/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 01:07:29 by fklein            #+#    #+#             */
/*   Updated: 2015/11/06 16:08:54 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define BUF_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putchar_error(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);

#endif
