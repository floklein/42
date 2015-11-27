/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:49:41 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:34:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	ft_exec_bin(t_socket *so)
{
	int		father;
	int		fd[2];
	int		fd2[2];

	pipe(fd);
	pipe(fd2);
	father = fork();
	if (father == 0)
	{
		close(fd[0]);
		close(fd2[0]);
		dup2(fd[1], 1);
		dup2(fd[1], 2);
		execv(so->tab[0], so->tab);
		ft_send_msg(so, "exec error: ", 1);
		ft_send_msg(so, so->tab[0], 1);
		ft_send_msg(so, " not found", 0);
		exit(0);
	}
	close(fd[1]);
	close(fd2[1]);
	ft_send_msg(so, "SUCCESS\n", 1);
	ft_read_and_send(so, fd[0], 1);
	ft_read_and_send(so, fd[0], 0);
	wait4(0, 0, 0, 0);
}

t_socket	*ft_init_socket(int ac, char **av)
{
	char 		*tmp;
	t_socket	*so;

	if (ac != 2)
		ft_error(av[0], 0);
	so = malloc(sizeof(t_socket));
	so->cmd_list = ft_init_cmd();
	tmp = getcwd(NULL, 0);
	so->home = ft_strjoin(tmp, "/");
	free(tmp);
	so->pwd = ft_strdup(so->home);
	so->old_pwd = ft_strdup(so->pwd);
	so->port = ft_atoi(av[1]);
	so->sock = ft_create_server(so->port, av[0]);
	so->csina = malloc(sizeof(struct sockaddr_in));
	so->cslen = 16;
	return (so);
}

int		ft_search_slash(char *str, int i)
{
	while (str[i] != '/' && i >= 0)
		i--;
	return (i);
}

int		ft_create_server(int port, char *str)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sina;

	proto = getprotobyname("tcp");
	if (proto == NULL)
		ft_error(str, 1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sina.sin_family = AF_INET;
	sina.sin_port = htons(port);
	sina.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sina, sizeof(sina)) == -1)
		ft_error(str, 1);
	listen(sock, 42);
	return (sock);
}
