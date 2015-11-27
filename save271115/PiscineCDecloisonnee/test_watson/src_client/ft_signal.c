#include "libft.h"
#include "client.h"

void	ft_signal(void)
{
	signal(SIGINT, &ft_ctrl_c);
	signal(SIGPIPE, &ft_pipe);
}

void	ft_ctrl_c(int c)
{
	(void)c;
	ft_send_msg(g_so, "quit", 0);
	close(g_so->sock);
	free(g_so);
	exit(0);
}

void	ft_pipe(int c)
{
	(void)c;
	close(g_so->sock);
	free(g_so);
	ft_printf("Error: server not found\nClient exiting...\n");
	exit(0);
}
