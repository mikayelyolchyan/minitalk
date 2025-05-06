/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:16 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/07 00:44:27 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static volatile t_state	g_state = {0, 0};

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;

	if (signal == SIGUSR1)
		g_state.current_char |= (1 << (7 - g_state.bit_count));
	g_state.bit_count++;
	if (g_state.bit_count == 8)
	{
		ft_printf("%c", g_state.current_char);
		g_state.current_char = 0;
		g_state.bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa;

	if (argc != 1)
	{
		ft_printf("Error: usage ./server\n");
		return (1);
	}	
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
