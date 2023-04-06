/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/06 12:11:49 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


static void f_handler(int sign, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sign == SIGUSR1)
	{
		ft_printf("SIG1 ok\n");
		ft_printf("%d\n", info->si_pid);
		kill(info->si_pid, SIGUSR2);
		exit(EXIT_SUCCESS);
	}
	if (sign == SIGUSR2)
	{
		ft_printf("SIG2 ok \n");
		ft_printf("%d\n", info->si_pid);
	}


}




int main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa_hand;
	sa_hand.sa_sigaction = f_handler;
	if (argc > 1)
	{
		ft_printf( "🚨"R" Error "W": There are too many arguments \n");
		return (0);
	}
	sigaction(SIGUSR1, &sa_hand, NULL);
	sigaction(SIGUSR2, &sa_hand, NULL);
	ft_printf(G "Le pid est : %d\n"W , getpid());
	while(argc == 1)
	{
		pause();
	}
	ft_printf("ok\n");
	return (0);

}