/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemzouri <kemzouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:57:08 by kemzouri          #+#    #+#             */
/*   Updated: 2025/03/28 22:24:24 by kemzouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_handler(int signum, siginfo_t *info, void *context);
int		ft_atoi(char *str);
void	handler(int signum);
void	send_char(unsigned char c, size_t pid);
void	ft_error(void);
void	wait_for_ack(int *retries);
int		check_pid_validity(char *str);

#endif
