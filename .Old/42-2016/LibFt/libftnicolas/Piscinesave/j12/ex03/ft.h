/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:19:51 by nthibaud          #+#    #+#             */
/*   Updated: 2016/04/06 16:25:41 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putchar_stderr(char c);
void	ft_putstr(char *str);
void	ft_putstr_stderr(char *str);
void	ft_putnbr(int nbr);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *s1, char *s2);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*int_conv(char *tab, int nb);
char	*int_to_char(char c, char *tab);
void	display_errno(char *arg_name);
void	display_invalid(char invalid_letter);
int		ft_hexdump(char **av, int ac);
int		check_valid_files_hex(char **av, int ac, int *count_valid);
int		file_is_invalid_hex(char *av);
void	display_hex(char *str, int *count_valid, int *char_nb);
void	display_tab_hex(char *str);
void	display_count_hex(int *char_nb, int *count_valid);
void	display_space_hex(int *count_valid);
void	init_count_valid_hex(int *count_valid);
int		ft_hexdump_opt(char **av, int ac, int option_nb);
int		check_valid_files_opt(char **av, int ac, int *count_valid);
int		file_is_invalid_opt(char *av);
void	display_opt(char *str, int *count_valid, int *char_nb);
void	display_tab_opt(char *str);
void	display_count_opt(int *char_nb);
void	display_space_opt(int *count_valid);
void	display_char_opt(char *tab);
void	init_count_valid_opt(int *count_valid, int option_nb);
void	tab_cmp(int *count_valid, int *char_nb, int *identical);
int		ft_hexdump_input(void);
void	display_input(char *str, int *count_valid, int *char_nb);
int		ft_hexdump_inopt(int option_nb);
void	display_inopt(char *str, int *count_valid, int *char_nb);
#endif
