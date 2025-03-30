/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:35:50 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/29 21:55:21 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_flag = 0;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag = 1;
}

void	ft_error(void)
{
	write(2, "Error sending signal\n", 21);
	exit(1);
}

void	wait_for_ack(int *retries)
{
	while (g_flag == 0 && *retries >= 0)
	{
		usleep(10);
		(*retries)--;
	}
	if (g_flag == 0)
		exit(1);
}

void	send_char(unsigned char c, size_t pid)
{
	unsigned char	bit;
	int				i;
	int				retries;

	retries = 500;
	i = 7;
	while (i >= 0)
	{
		bit = c >> i & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error();
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				ft_error();
		wait_for_ack(&retries);
		g_flag = 0;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (check_pid_validity(argv[1]) == 0)
			return (write(1, "Only numbers are valid!\n", 24));
		pid = ft_atoi(argv[1]);
		if (pid == -1 || pid == 0)
			return ((write(2, "Error invalid pid\n", 18)), -1);
		signal(SIGUSR1, handler);
		while (argv[2][i] != '\0')
		{
			send_char((unsigned char)argv[2][i], pid);
			i++;
		}
		send_char('\0', pid);
	}
	else
		write(2, "Error\n", 6);
}
