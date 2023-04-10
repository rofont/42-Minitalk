/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/09 10:23:12 by romain           ###   ########.fr       */
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
	}
	if (sign == SIGUSR2)
	{
		printf("SIG2 ok \n");
		printf("%d\n", info->si_pid);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	struct sigaction sa_ha;
	sa_ha.sa_sigaction = f_handler;
	if (argc != 3)
	{
		printf( "🚨"R" Error "W": Need arguments ./client <PID> <MESSAGE> \n");
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &sa_ha, NULL);
	sigaction(SIGUSR2, &sa_ha, NULL);
	printf("%d, %s, ok\n", ft_atoi(argv[1]), argv[2]);
	if (ft_strlen(argv[2]) == 1)
	{
		kill(ft_atoi(argv[1]), SIGUSR1);
		printf("%d\n", getpid());
	}
	else
	{
		kill(ft_atoi(argv[1]), SIGUSR2);
		printf("%d\n", getpid());
	}
	while(1)
		pause();
	return (0);
}