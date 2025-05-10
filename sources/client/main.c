/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:21 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/10 23:41:14 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static int	g_bit_sent;

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (signal == SIGUSR1)
	{
		ft_printf("Youre messege is sent\n");
	}
	if (signal == SIGUSR2)
	{
		g_bit_sent = 1;
	}
}

void	send_char_bit_by_bit(int server_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_bit_sent = 0;
		if (((c >> i) & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i--;
		usleep(100);
		while (g_bit_sent == 0)
			pause();
	}
}

void	send_string_bit_by_bit(int server_pid, const char *str)
{
	while (*str)
	{
		send_char_bit_by_bit(server_pid, (unsigned char)*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc != 3)
	{
		ft_printf("Error, usage: ./server <PID> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 1);
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_string_bit_by_bit(server_pid, argv[2]);
	send_char_bit_by_bit(server_pid, '\0');
	send_char_bit_by_bit(server_pid, '\n');
	return (0);
}
