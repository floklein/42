/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:50:11 by flklein           #+#    #+#             */
/*   Updated: 2018/09/08 22:46:59 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		**create_tab(char **av);
int		**copy_tab(int **old);
void	print_tab(int **tab);
int		test(int **tab, int pos, int nb);

#endif
