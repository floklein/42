/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 21:39:44 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/25 16:46:13 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

int		ft_search_slash(char *str, int i)
{
	while (str[i] != '/' && i >= 0)
		i--;
	return (i);
}

int		ft_create_client(char *addr, int port, char *str)
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
	if (!ft_strcmp("localhost", addr))
		sina.sin_addr.s_addr = inet_addr("127.0.0.1");
	else
		sina.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sina, sizeof(sina)) == -1)
		ft_error(str, 1);
	return (sock);
}

void	ft_exec_bin(t_socket *so)
{
	int		father;

	father = fork();
	if (father == 0)
	{
		execv(so->tab[0], so->tab);
		exit(0);
	}
	wait4(0, 0, 0, 0);
}
