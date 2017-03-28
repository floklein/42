/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:28:16 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/02 21:35:44 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define BUFFSIZE 32768 
# define READSIZE 1
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int		ft_strlen(char *s);
void	ft_putstr(int fd, char *s);
void	ft_putnstr(int fd, char *s, int size);
int		ft_strjoin(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);


#endif
