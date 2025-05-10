/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:16 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/10 20:49:47 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static char	current_char;
	static int	bit_count;

	(void)ucontext;
	if (signal == SIGUSR1)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", current_char);
		if (current_char == '\0')
		{
			kill(info->si_pid, SIGUSR1);
		}
		current_char = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: usage ./server\n");
		return (1);
	}
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
