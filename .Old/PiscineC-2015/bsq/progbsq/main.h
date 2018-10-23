/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:06:35 by cchaumar          #+#    #+#             */
/*   Updated: 2015/11/06 23:14:39 by fklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define PRINT_SPACES 0

typedef struct	s_map
{
	char			*charset;
	int				width;
	int				height;
}				t_map;

typedef struct	s_list
{
	char			c;
	struct s_list	*next;
}				t_list;

typedef struct	s_bsq
{
	int				i;
	int				j;
	int				size;
}				t_bsq;

t_list			*ft_create_elem(void);
char			*ft_list_to_tab(t_list *root, int deep);
void			ft_list_push_back(t_list **root);
void			ft_putstr(int fd, char *s);
int				ft_strlen(char *s);
char			*ft_strdup(char *src);
int				f_strcmp(char *s1, char *s2);
int				ft_atoi(char *s);
int				ft_strf(char c, char *s);
int				ft_check_eol(int i, int n, char *s);
void			ft_bsq(char **map, t_map *charset);
void			ft_print_map(char **map, int flag);
void			ft_run_bsq(char **map, t_map *info);
void			ft_destroy(t_list *root);

#endif
