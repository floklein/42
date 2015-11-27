#include "libft.h"
#include "server.h"

void	ft_signal(void)
{
	signal(SIGINT, &ft_ctrl_c);
}

void	ft_ctrl_c(int c)
{
	(void)c;
	ft_printf("Server close\n");
	close(g_so->sock);
	free(g_so);
	exit(0);
}
