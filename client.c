#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// void	convertback(char *byte)
// {
// 	int i;
// 	int num;

// 	i = 0;
// 	num = 0;
// 	while (i < 8)
// 	{
// 		if (byte[i] == 1)
// 		{
// 			num++;
// 			num <<= 1;
// 		}
// 		else
// 		{
// 			num <<= 1;
// 		}
// 		i++;
// 	}
// 	printf("num: %d\n", num);
// }

void	sendbit(char c, int pid)
{
	(void)pid;
	int	i;
	int	check;
	int sum;

	i = 0;
	check = 128;
	sum = 0;
	while (i < 8)
	{
		if ((check & c) >= 128)
		{	
			// kill(SIGUSR1, pid);
			printf("1");
			sum <<= 1;
			sum += 1;
		}
		else
		{
			// kill(SIGUSR2, pid);
			printf("0");
			sum <<= 1;
		}
		c <<= 1;
		i += 1;;
	}
	printf("\nfinal sum: %d\n", sum);
}

void	sendmessage(char *msg, int pid)
{
	int i;

	i = 0;
	while (msg[i] != '\0')
	{
		sendbit(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	int pid;

	pid = atoi(av[1]);
	sendmessage(av[2], pid);
	// printf("\n%d\n", (128 & 107));
	return (0);
}