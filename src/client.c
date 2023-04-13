/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/13 10:37:06 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	f_error(t_client *send)
{
	printf("🚨"RED" Error : \n");
	printf(WHT"Arguments error\n");
	free(send->msg);
	free(send);
	exit(EXIT_FAILURE);
}

static void	f_handler_client(int sign, siginfo_t *info, void *ucontext_t)
{
	static t_client	*send;
	int				flag;

	(void)info;
	(void)ucontext_t;
	flag = 0;
	send = f_init_client(0, 0);
	if (sign == SIGUSR1)
		f_msg_received(send);
	if (sign == SIGUSR2)
	{
		if ((send->len >= 0) && (send->msg[send->index] & (128 >> send->bits)))
			flag = kill(send->pid_s, SIGUSR2);
		else
			flag = kill(send->pid_s, SIGUSR1);
		send->bits++;
		if (send->bits == 8)
		{
			send->index++;
			send->bits = 0;
			send->len--;
		}
	}
	if (flag == -1)
		f_error(send);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_client;
	t_client			*send;

	if (argc != 3)
	{
		printf("🚨"RED" Error : \n");
		printf(WHT"Need arguments [./client <PID> <MESSAGE>]\n");
		exit(EXIT_FAILURE);
	}
	send = f_init_client(argv[1], argv[2]);
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = f_handler_client;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	kill(getpid(), SIGUSR2);
	while (1)
		pause();
	free(send->msg);
	free(send);
	return (0);
}
