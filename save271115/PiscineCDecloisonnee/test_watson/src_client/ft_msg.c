/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 21:39:11 by nsavry            #+#    #+#             */
/*   Updated: 2015/08/25 18:57:20 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

int		ft_send_msg(t_socket *so, char *str, int te)
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
		send(so->sock, &nb, 4, 4);
		send(so->sock, tmp, BUF_SIZE - 1, 4);
		len -= BUF_SIZE - 1;
		i++;
	}
	free(tmp);
	if (ft_send_msg_buf(so, str + (i * (BUF_SIZE - 1)), 1) == -1)
		return (-1);
	if (te == 0)
		send(so->sock, &te, 4, 4);
	return (0);
}

int		ft_send_msg_buf(t_socket *so, char *str, int te)
{
	char	*tmp;
	int		nb;

	nb = BUF_SIZE - 1;
	tmp = malloc(sizeof(char) * BUF_SIZE);
	ft_bzero(tmp, BUF_SIZE);
	tmp = ft_strcpy(tmp, str);
	send(so->sock, &nb, 4, 4);
	if (send(so->sock, tmp, BUF_SIZE - 1, 4) == -1)
	{
		free(tmp);
		return (-1);
	}
	if (te == 0)
		send(so->sock, &te, 4, 4);
	free(tmp);
	return (0);
}

void	ft_read_and_send(t_socket *so, int fd, int te)
{
	ft_bzero(so->buf, BUF_SIZE);
	while ((so->r = read(fd, so->buf, BUF_SIZE - 1)))
	{
		so->buf[so->r] = 0;
		send(so->sock, &so->r, 4, 4);
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
		send(so->sock, so->buf, BUF_SIZE - 1, 4);
		ft_bzero(so->buf, BUF_SIZE);
	}
	so->r = 0;
	if (te == 0)
		send(so->sock, &so->r, 4, 4);
}

void	ft_receive(t_socket *so, int fd)
{
	int		nb;
	int		r;

	recv(so->sock, &nb, 4, 0);
	while (nb != 0)
	{
		ft_bzero(so->buf, BUF_SIZE);
		r = recv(so->sock, so->buf, BUF_SIZE - 1, 0);
		so->buf[r] = 0;
		write(fd, so->buf, nb);
		recv(so->sock, &nb, 4, 0);
	}
}
