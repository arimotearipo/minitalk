#include "minitalk.h"

void	handler(int signum)
{
	static char	c;
	static int	bitcount;

	if (signum == SIGUSR1)
	{
		c <<= 1;
		c += 1;
		bitcount++;
	}
	else if (signum == SIGUSR2)
	{
		c <<= 1;
		bitcount++;
	}
	if (bitcount == 8)
	{
		write(1, &c, 1);
		bitcount = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("pid: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
