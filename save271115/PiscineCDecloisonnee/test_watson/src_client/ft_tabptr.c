#include "libft.h"
#include "client.h"

char	**ft_init_cmd(void)
{
	char	**tab;

	ft_cmd[0] = ft_lls;
	ft_cmd[1] = ft_lpwd;
	ft_cmd[2] = ft_lcd;
	ft_cmd[3] = ft_get;
	ft_cmd[4] = ft_put;
	ft_cmd[5] = ft_other;
	tab = malloc(sizeof(char *) * 6);
	tab[0] = ft_strdup("lls");
	tab[1] = ft_strdup("lpwd");
	tab[2] = ft_strdup("lcd");
	tab[3] = ft_strdup("get");
	tab[4] = ft_strdup("put");
	tab[5] = NULL;
	return (tab);
}

void	ft_other(t_socket *so)
{
	(void)so;
	//ft_send_msg(so, "ERROR\n", 1);
	//ft_send_msg(so, so->tab[0], 1);
	//ft_send_msg(so, " not found\n", 0);
}
