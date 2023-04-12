/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/12 14:17:55 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


static void f_handler_serv(int sign, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	static t_serv	*recup;

	printf("pid_si : %d", info->si_pid);
	fflush(stdout);
	if (!recup)
		recup = f_init_serv(info->si_pid);
	if (sign == SIGUSR2)
		recup->box |=(128 >> recup->bits);
	if (++recup->bits == 8)
	{
		if (recup->box != '\0')
		{
			recup->msg = f_stock_char(recup->msg, recup->box);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			recup->msg = f_stock_char(recup->msg, recup->box);
			printf("%s\n", recup->msg);
			free(recup->msg);
			recup->msg = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		recup->box = 0;
		recup->bits = 0;
	}
	else
		kill(info->si_pid, SIGUSR2);

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
	sa_serv.sa_flags = SA_SIGINFO;
	sa_serv.sa_sigaction = f_handler_serv;
	sigaction(SIGUSR1, &sa_serv, NULL);
	sigaction(SIGUSR2, &sa_serv, NULL);
	printf(G "Le pid est : %d "W"\n" , getpid());
	while(1)
		pause();
	return (0);

}