/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:44 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:34:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <dirent.h>

# include <sys/times.h>
# include <sys/resource.h>
# include <sys/wait.h>

# define BUF_SIZE 10

typedef struct	s_socket
{
	int					port;
	int					sock;
	unsigned int		cslen;
	struct sockaddr_in	*csina;
	int					cs;
	int					r;
	char				buf[BUF_SIZE];
	char				**tab;
	char				**cmd_list;
	char				*pwd;
	char				*old_pwd;
	char				*home;
	char				*cmd;
}				t_socket;

t_socket		*g_so;

void	(*ft_cmd[6])(t_socket *so);

char	**ft_init_cmd(void);
void	ft_other(t_socket *so);

void	ft_signal(void);
void	ft_ctrl_c(int c);

void	ft_ls(t_socket *so);
void	ft_pwd(t_socket *so);
void	ft_cd(t_socket *so);
void	ft_get(t_socket *so);
void	ft_put(t_socket *so);

void	ft_read_and_send(t_socket *so, int fd, int te);
void	ft_send_msg_buf(t_socket *so, char *str, int te);
void	ft_send_msg(t_socket *so, char *str, int te);
void	ft_receive_cmd(t_socket *so);
void	ft_receive(t_socket *so, int fd);

void	ft_error(char *str, int err);

int		ft_create_server(int port, char *str);
void	ft_exec_bin(t_socket *so);
int		ft_search_slash(char *str, int i);
t_socket	*ft_init_socket(int ac, char **av);

void	ft_protect_pwd(t_socket *so);
void	ft_remove_current(t_socket *so, int i);
void	ft_remove_before(t_socket *so, int i);
void	ft_remove_double(t_socket *so, int i);

#endif
