/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:05:02 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/03/15 12:13:17 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendbit(char c, int pid)
{
	int	i;
	int	check;

	i = 0;
	check = 128;
	while (i < 8)
	{
		if ((check & c) == 128)
		{	
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("Error\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("Error\n");
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
	sendbit('\0', pid);
}

static void	c_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		ft_printf("Complete message sent to server!\n");
}

int	main(int ac, char **av)
{
	struct sigaction	clientsa;
	int					pid;
	int					msglen;

	if (ac != 3)
	{
		ft_printf("To use:\n./client \"Server PID\" \"message\"\n");
		return (0);
	}
	clientsa.sa_sigaction = c_handler;
	clientsa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &clientsa, NULL);
	pid = ft_atoi(av[1]);
	msglen = ft_strlen(av[2]);
	sendmessage(av[2], pid);
	return (0);
}
