/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:31:50 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/25 18:57:20 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	ft_send_msg(t_socket *so, char *str, int te)
{
	char	*tmp;
	char	*sa;
	int		len;
	int		i;
	int		nb;

	nb = BUF_SIZE - 1;
	len = ft_strlen(str);
	i = 0;
	tmp = malloc(sizeof(char) * BUF_SIZE);
	while ((len / (BUF_SIZE - 1)) != 0)
	{
		ft_bzero(tmp, BUF_SIZE);
		sa = str + (i * (BUF_SIZE - 1));
		tmp = ft_strncpy(tmp, sa, BUF_SIZE - 1);
		tmp[BUF_SIZE - 1] = 0;
		send(so->cs, &nb, 4, 4);
		send(so->cs, tmp, BUF_SIZE - 1, 4);
		len -= BUF_SIZE - 1;
		i++;
	}
	ft_send_msg_buf(so, str + (i * (BUF_SIZE - 1)), 1);
	if (te == 0)
		send(so->cs, &te, 4, 4);
	free(tmp);
}

void	ft_send_msg_buf(t_socket *so, char *str, int te)
{
	char	*tmp;
	int		nb;

	nb = BUF_SIZE - 1;
	tmp = malloc(sizeof(char) * BUF_SIZE);
	ft_bzero(tmp, BUF_SIZE);
	tmp = ft_strcpy(tmp, str);
	send(so->cs, &nb, 4, 4);
	send(so->cs, tmp, BUF_SIZE - 1, 4);
	if (te == 0)
		send(so->cs, &te, 4, 4);
	free(tmp);
}

void	ft_read_and_send(t_socket *so, int fd, int te)
{
	ft_bzero(so->buf, BUF_SIZE);
	while ((so->r = read(fd, so->buf, BUF_SIZE - 1)))
	{
		so->buf[so->r] = 0;
		send(so->cs, &so->r, 4, 4);
		if (so->r != (BUF_SIZE - 1))
		{
			int		i;
			i = so->r;
			while (i < BUF_SIZE)
			{
				so->buf[i] = 0;
				i++;
			}
		}
		send(so->cs, so->buf, BUF_SIZE - 1, 4);
		ft_bzero(so->buf, BUF_SIZE);
	}
	so->r = 0;
	if (te == 0)
		send(so->cs, &so->r, 4, 4);
}

void	ft_receive_cmd(t_socket *so)
{
	char	*tmp;
	int		r;
	int		nb;

	recv(so->cs, &nb, 4, 0);
	so->cmd = malloc(sizeof(char));
	so->cmd[0] = 0;
	so->r = 0;
	while (nb != 0)
	{

		ft_bzero(so->buf, BUF_SIZE);
		r = recv(so->cs, so->buf, BUF_SIZE - 1, 0);
		so->buf[r] = 0;
		tmp = so->cmd;
		so->cmd = ft_strjoin(so->cmd, so->buf);
		free(tmp);
		recv(so->cs, &nb, 4, 0);
	}
}

void	ft_receive(t_socket *so, int fd)
{
	int		nb;
	int		r;

	recv(so->cs, &nb, 4, 0);
	while (nb != 0)
	{
		ft_bzero(so->buf, BUF_SIZE);
		r = recv(so->cs, so->buf, BUF_SIZE - 1, 0);
		so->buf[r] = 0;
		write(fd, so->buf, nb);
		recv(so->cs, &nb, 4, 0);
	}
}
