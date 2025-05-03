#include "../../includes/headers/minitalk.h"

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("Server pid: %d\n", pid);
	return (0);
}