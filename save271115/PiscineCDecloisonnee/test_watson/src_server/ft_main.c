/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:47 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/25 18:57:20 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

int		main(int ac, char **av)
{
	int			i;
	t_socket	*so;
	pid_t		father;
	char		*addr;

	so = ft_init_socket(ac, av);
	ft_signal();
	g_so = so;
	while (1)
	{
		so->cs = accept(so->sock, (struct sockaddr *)so->csina, &so->cslen);
		father = fork();
		if (father == 0)
		{
			addr = inet_ntoa(so->csina->sin_addr);
			ft_printf("New connection from %s!\n", addr);
			ft_receive_cmd(so);
			while (ft_strcmp(so->cmd, "quit") != 0)
			{
				ft_printf("received %d bytes: [%s] from %s\n", ft_strlen(so->cmd), so->cmd, addr);
				so->tab = ft_strsplit(so->cmd, ' ');
				free(so->cmd);
				i = 0;
				while (so->cmd_list[i] != NULL)
				{
					if (ft_strcmp(so->tab[0], so->cmd_list[i]) == 0)
						break ;
					i++;
				}
				ft_protect_pwd(so);
				ft_cmd[i](so);
				ft_receive_cmd(so);
			}
			close(so->cs);
			ft_printf("Connection lost from %s!\n", addr);
			exit(0);
		}
	}
	close(so->sock);
	return (0);
}
