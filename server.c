/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:04:51 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/03/15 12:18:02 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (c == '\0')
			kill(siginfo->si_pid, SIGUSR1);
		write(1, &c, 1);
		bitcount = 0;
	}
}

static	void	siginthandler(int signum, siginfo_t *siginfo, void *context)
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
	sa2.sa_sigaction = siginthandler;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa2, NULL);
	pid = getpid();
	ft_printf("Server launched! PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
