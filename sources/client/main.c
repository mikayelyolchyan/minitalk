/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:35:21 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/07 00:32:22 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

void	send_char_bit_by_bit(int server_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_string_bit_by_bit(int server_pid, const char *str)
{
	while (*str)
	{
		send_char_bit_by_bit(server_pid, (unsigned char)*str);
		str++;
		usleep(100);
	}
	send_char_bit_by_bit(server_pid, '\n');
}

int	main(int argc, char **argv)
{
	int	server_pid;

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
	send_string_bit_by_bit(server_pid, argv[2]);
	return (0);
}
