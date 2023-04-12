/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/11 22:11:14 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


static void f_handler_client(int sign, siginfo_t *info, void *ucontext_t)
{
	(void)info;
	(void)ucontext_t;
	static t_client	*send;

	if (sign == SIGUSR1)

	if (sign == SIGUSR2)
}

int main(int argc, char **argv)
{
	struct sigaction	sa_client;
	t_client			*send;

	if (argc != 3)
	{
		printf( "🚨"R" Error "W": Need arguments ./client <PID> <MESSAGE> \n");
		exit(EXIT_FAILURE);
	}
	send = ft_init_client(argv[1], argv[2]);
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = f_handler_client;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	while(1)
		pause();

	return (0);
}