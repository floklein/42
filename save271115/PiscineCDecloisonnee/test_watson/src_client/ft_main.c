/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:37 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:34:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_socket	*so;
	char		*line;
	int			i;

	if (ac != 3)
		ft_error(av[0], 0);
	ft_signal();
	so = malloc(sizeof(t_socket));
	so->port = ft_atoi(av[2]);
	so->sock = ft_create_client(av[1], so->port, av[0]);
	so->cmd = ft_init_cmd();
	g_so = so;
	ft_printf("$> ");
	line = ft_strdup("lol");
	while (ft_get_next_line(0, &line) > 0 && ft_strcmp(line, "quit"))
	{
		i = 0;
		if (*line)
		{
			so->tab = ft_strsplit(line, ' ');
			while (so->cmd[i] != NULL)
			{
				if (ft_strcmp(so->cmd[i], so->tab[0]) == 0)
					break;
				i++;
			}
			if (i > 2)
				ft_send_msg(so, line, 0);
			ft_cmd[i](so);
			if (i > 2)
				ft_receive(so, 1);
		}
		ft_printf("$> ");
	}
	ft_send_msg(so, "quit", 0);
	if (so->tab)
		free(so->tab);
	free(so);
	close(so->sock);
	return (0);
}
