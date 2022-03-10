#include "minitalk.h"

void	sendbit(char c, int pid)
{
	int	i;
	int	check;

	i = 0;
	check = 128;
	while (i < 8)
	{
		if ((check & c) >= 128)
		{	
			if (kill(pid, SIGUSR1) == -1)
				write(1, "Error\n", 6);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(1, "Error\n", 6);
		}
		c <<= 1;
		i += 1;
		usleep(50);
	}
}

void	sendmessage(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		sendbit(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)ac;
	pid = atoi(av[1]);
	sendmessage(av[2], pid);
	return (0);
}
