/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:50:11 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 02:37:31 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
char	**create_tab(char **av);
int		**copy_tab(int **old);
void	print_tab(char **tab);
int		test(char **tab, int pos, char nb);

#endif
