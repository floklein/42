/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:42:41 by flklein           #+#    #+#             */
/*   Updated: 2018/09/17 14:25:52 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 4096

void	ft_putchar(char c);
void	ft_putchar_err(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);

#endif
