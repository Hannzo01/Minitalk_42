/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:18:30 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/29 20:59:06 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_old_pid = 0;

void	print_byte(char byte)
{
	if (byte == '\0')
	{
		write(1, "\n", 1);
		g_old_pid = 0;
	}
	else
		write(1, &byte, 1);
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static char	byte = 0;
	static int	i = 8;
	pid_t		current_pid;

	(void)context;
	if (g_old_pid == 0)
		g_old_pid = info->si_pid;
	current_pid = info->si_pid;
	if (info->si_pid != g_old_pid)
	{
		byte = 0;
		i = 8;
		g_old_pid = 0;
	}
	byte = byte << 1;
	if (signum == SIGUSR1)
		byte = byte | 1;
	i--;
	if (i == 0)
	{
		print_byte(byte);
		byte = 0;
		i = 8;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 1)
		return (write(1, "Error\nusage: ./server\n", 23), 1);
	pid = getpid();
	write(1, "Server is running with PID: ", 28);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	(void)av;
	return (0);
}
