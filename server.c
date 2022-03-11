#include "libft/libft.h"
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
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
