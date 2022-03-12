#include "minitalk.h"

static void	s_handler(int signum, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	bitcount;

	(void)context;
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
		kill(siginfo->si_pid, SIGUSR1);
	}
}

static	void	inthandler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGINT)
	{
		ft_printf("\nServer terminated.\n");
		exit(3);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	struct sigaction	sa2;

	sa.sa_sigaction = s_handler;
	sa.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = inthandler;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa2, NULL);
	pid = getpid();
	ft_printf("Server has started!\nPID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
