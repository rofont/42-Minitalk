/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/13 08:07:21 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	f_handler_client(int sign)
{
	static t_client	*send;

	send = f_init_client(0, 0);
	if (sign == SIGUSR1)
		f_msg_received(send);
	if (sign == SIGUSR2)
	{
		if ((send->len >= 0) && (send->msg[send->index] & (128 >> send->bits)))
			kill(send->pid_s, SIGUSR2);
		else
			kill(send->pid_s, SIGUSR1);
		send->bits++;
		if (send->bits == 8)
		{
			send->index++;
			send->bits = 0;
			send->len--;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;
	t_client			*send;

	if (argc != 3)
	{
		ft_printf("🚨"RED" Error : "WHT"Need arguments : ./client <PID> <MESSAGE> \n");
		exit(EXIT_FAILURE);
	}
	send = f_init_client(argv[1], argv[2]);
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_handler = f_handler_client;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	kill(getpid(), SIGUSR2);
	while (1)
		pause();
	free(send->msg);
	free(send);
	return (0);
}
