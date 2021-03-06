/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:16:54 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 00:47:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# define BUF_SIZE 4096

void	ft_putchar(char c);
void	ft_putchar_err(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_abs(int nb);
int		is_numeric(char *str);
void	ft_file_error(char *file);
void	ft_offset_error(char *offset);
void	ft_usage_error(void);

#endif
