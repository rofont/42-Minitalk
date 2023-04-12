/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/11 21:59:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


static void f_handler_serv(int sign, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	static t_serv	*recup;

	if (!recup)
		recup = f_init_serv(info->si_pid);
	if (sign == SIGUSR1)

	if (sign == SIGUSR2)
}

int main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa_serv;

	if (argc > 1)
	{
		printf( "🚨"R" Error "W": No argument needed \n");
		exit(EXIT_FAILURE);
	}
	sa_serv.sa_sigaction = f_handler_serv;
	sigaction(SIGUSR1, &sa_serv, NULL);
	sigaction(SIGUSR2, &sa_serv, NULL);
	printf(G "Le pid est : %d\n"W , getpid());
	while(1)
		pause();
	return (0);

}