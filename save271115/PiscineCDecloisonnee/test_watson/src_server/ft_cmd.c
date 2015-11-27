/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:49:46 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/26 22:34:26 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	ft_ls(t_socket *so)
{
	char	*tmp;

	tmp = so->tab[0];
	so->tab[0] = ft_strjoin("/bin/", tmp);
	free(tmp);
	ft_exec_bin(so);
}

void	ft_pwd(t_socket *so)
{
	ft_send_msg(so, "SUCCES\n", 1);
	ft_send_msg(so, so->pwd + ft_strlen(so->home) - 1, 1);
	ft_send_msg(so, "\n", 0);
}

void	ft_cd(t_socket *so)
{
	char	*tmp;
	
	if (so->tab[1] == NULL)
		tmp = so->home;
	else if (ft_strcmp(so->tab[1], "-") == 0)
		tmp = so->old_pwd;
	else
		tmp = so->tab[1];
	if (chdir(tmp) == 0)
	{
		tmp = so->old_pwd;
		so->old_pwd = ft_strdup(so->pwd);
		free(tmp);
		tmp = so->pwd;
		so->pwd = getcwd(NULL, 0);
		free(tmp);
		tmp = so->pwd;
		so->pwd = ft_strjoin(so->pwd, "/");
		free(tmp);
		ft_send_msg(so, "SUCCESS\n", 0);
	}
	else
		ft_send_msg(so, "ERROR\n", 0);
	ft_printf("pwd:%s\noldpwd:%s\nhome:%s\n", so->pwd, so->old_pwd, so->home);
}

void	ft_get(t_socket *so)
{
	int		fd;
	int		nb;

	if (so->tab[1] != NULL)
	{
		if (opendir(so->tab[1]) == NULL)
			fd = open(so->tab[1], 0);
		else
			fd = -1;
		if (fd != -1)
		{
			nb = 1;
			send(so->cs, &nb, 1, 4);
			ft_read_and_send(so, fd, 0);
			ft_send_msg(so, "SUCCESS\n", 0);
			close(fd);
		}
		else
		{
			nb = 0;
			send(so->cs, &nb, 1, 4);
			ft_send_msg(so, "ERROR\nfile not found\n", 0);
		}
	}
	else
	{
		nb = 0;
		send(so->cs, &nb, 1, 4);
		ft_send_msg(so, "ERROR\nUsage: get file_name\n", 0);
	}
}

void	ft_put(t_socket *so)
{
	int		fd;
	int		k;
	char	*str;
	char	*tmp;
	char	nb;

	if (so->tab[1])
	{
		recv(so->cs, &nb, 1, 0);
		if (nb == 1)
		{
			k = ft_search_slash(so->tab[1], ft_strlen(so->tab[1]));
			str = ft_strdup(so->tab[1] + k + 1);
			while ((fd = open(str, O_RDONLY)) != -1)
			{
				tmp = str;
				str = ft_strjoin(tmp, "_cpy");
				free(tmp);
				close(fd);
			}
			fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0777);
			free(str);
			ft_receive(so, fd);
			ft_send_msg(so, "SUCCESS\n", 0);
			close(fd);
		}
		else
			ft_send_msg(so, "ERROR\nFile not found\n", 0);
	}
	else
		ft_send_msg(so, "ERROR\nUsage: put file_name\n", 0);
}
