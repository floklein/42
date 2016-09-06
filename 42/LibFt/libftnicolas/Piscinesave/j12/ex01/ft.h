/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:21:11 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 10:31:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

void	ft_putchar(char c);
void	ft_putchar_stderr(char c);
void	ft_putstr(char *str);
void	ft_putstr_stderr(char *str);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);

#endif
