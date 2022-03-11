#include "libft/libft.h"
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
		usleep(DELAY);
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

void	instruction(void)
{
	write(1, "To use:\n", 8);
	write(1, "./client \"PID number\" \"message\"\n", 36);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		instruction();
		return (0);
	}
	pid = ft_atoi(av[1]);
	sendmessage(av[2], pid);
	return (0);
}
