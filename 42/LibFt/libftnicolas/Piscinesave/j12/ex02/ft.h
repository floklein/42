/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:35:13 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/08 11:26:51 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putchar_stderr(char c);
void	ft_putstr(char *str);
void	ft_putstr_stderr(char *str);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);
int		option(int *bytes_nb, int ac, char **av);
int		ft_tail(int ac, char **av);
void	display_error(char *arg, int case_nb);
int		isnt_dir(char *av, int *arg_nb);
void	read_stdin(char *av, int *arg_nb);
void	display_header(char *av, int *arg_nb);
void	display_errno(char *arg_name);
int		case_one(char **av, int *plus, int *bytes_nb, int *i);
int		case_two(char **av, int *plus, int *bytes_nb, int *i);
int		check_arg(char *av, int *plus);
int		check_next_arg(char *av, int *plus);
int		char_to_int(char *av);
int		other_option(char **av, int i);
int		count_arg(int ac, char **av);
int		disp_file_end(int bytes_nb, char *av, int fd);
int		disp_file_begin(int bytes_nb, char *av, int fd);
int		display_file(char *av, int plus, int bytes_nb, int *arg_nb);
void	browse_arg(char **av, int ac, int ret, int bytes_nb);

#endif
