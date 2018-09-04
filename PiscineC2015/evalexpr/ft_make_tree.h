/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdesvern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 20:59:17 by cdesvern          #+#    #+#             */
/*   Updated: 2015/11/01 15:30:07 by cdesvern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAKE_TREE_H
# define FT_MAKE_TREE_H

char			*ft_strip_pth(char *str);
char			*ft_dead_space(char *str);
int				ft_strlen(char *str);
int				index_lowest_op(char *str);
int				ft_atoi(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);

typedef struct	s_node
{
	char			*val;
	struct s_node	*ls;
	struct s_node	*rs;
}				t_node;

t_node			*make_tree(char *str);
int				ft_calc_tree(t_node *tree);
void			ft_deforestation(t_node *tree);

#endif
