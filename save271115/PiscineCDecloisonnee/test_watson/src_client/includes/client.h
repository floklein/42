/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:39 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:34:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>

# define BUF_SIZE 10

typedef struct	s_socket
{
	char	buf[BUF_SIZE];
	int		sock;
	int		port;
	char	**tab;
	char	**cmd;
	int		r;
}				t_socket;

t_socket	*g_so;

void	(*ft_cmd[6])(t_socket *so);

char	**ft_init_cmd(void);
void	ft_other(t_socket *so);

void	ft_error(char *str, int err);

void	ft_signal(void);
void	ft_ctrl_c(int c);
void	ft_pipe(int c);

int		ft_create_client(char *addr, int port, char *str);
int		ft_search_slash(char *str, int i);
void	ft_exec_bin(t_socket *so);

int		ft_send_msg(t_socket *so, char *str, int te);
int		ft_send_msg_buf(t_socket *so, char *str, int te);
void	ft_read_and_send(t_socket *so, int fd, int te);
void	ft_receive(t_socket *so, int fd);

void	ft_get(t_socket *so);
void	ft_put(t_socket *so);
void	ft_lls(t_socket *so);
void	ft_lpwd(t_socket *so);
void	ft_lcd(t_socket *so);

#endif
