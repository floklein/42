#include "libft.h"
#include "client.h"

void	ft_get(t_socket *so)
{
	char	nb;
	int		fd;
	int		k;
	char	*str;
	char	*tmp;

	recv(so->sock, &nb, 1, 0);
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
		close(fd);

	}
}

void	ft_put(t_socket *so)
{
	char	nb;
	int		fd;

	if (so->tab[1])
	{
		if (opendir(so->tab[1]) == NULL &&
				(fd = open(so->tab[1], O_RDONLY)) != -1)
		{
			nb = 1;
			send(so->sock, &nb, 1, 4);
			ft_read_and_send(so, fd, 0);
		}
		else
		{
			nb = 0;
			send(so->sock, &nb, 1, 4);
		}
	}
}

void	ft_lls(t_socket *so)
{
	char	*tmp;

	tmp = so->tab[0];
	so->tab[0] = ft_strdup("/bin/ls");
	free(tmp);
	ft_exec_bin(so);
}

void	ft_lpwd(t_socket *so)
{
	(void)so;
	ft_printf("%s\n", getcwd(NULL, 0));
}

void	ft_lcd(t_socket *so)
{
	(void)so;
}
