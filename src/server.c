/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/09 14:55:53 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


static void f_handler(int sign, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	if (sign == SIGUSR1)
	{
		printf("SIG1 ok\n");
		printf("%d\n", info->si_pid);
		kill(info->si_pid, SIGUSR2);
		exit(EXIT_SUCCESS);
	}
	if (sign == SIGUSR2)
	{
		printf("SIG2 ok \n");
		printf("%d\n", info->si_pid);
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa_hand;
	sa_hand.sa_sigaction = f_handler;
	if (argc > 1)
	{
		printf( "🚨"R" Error "W": No argument needed \n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &sa_hand, NULL);
	sigaction(SIGUSR2, &sa_hand, NULL);
	printf(G "Le pid est : %d\n"W , getpid());
	while(1)
		pause();
	return (0);

}