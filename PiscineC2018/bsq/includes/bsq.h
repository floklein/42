/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:50:59 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 14:37:37 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 4096

typedef struct	s_params
{
	char	*map;
	int		lines;
	char	p;
	char	o;
	char	x;
}				t_params;

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putchar_err(char c);
void		ft_putstr_err(char *str);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
int			ft_atoi(char *str);
int			parse_map(t_params *par, char *map);

#endif
