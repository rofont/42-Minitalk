/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/12 21:34:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// printf("pid_si : %d", info->si_pid);
static void	f_handler_serv(int sign, siginfo_t *info, void *ucontext_t)
{
	static t_serv	*recup;

	(void)ucontext_t;
	// fflush(stdout);
	if (!recup)
		recup = f_init_serv(info->si_pid);
	if (recup && recup->pid_c != info->si_pid && info->si_pid != 0)
	{
		recup->pid_c = info->si_pid;
		recup->bits = 0;
		recup->box = 0;
	}
	if (sign == SIGUSR2)
		recup->box |= (128 >> recup->bits);
	if (++recup->bits == 8)
	{
		if (recup->box != '\0')
		{
			recup->msg = f_stock_char(recup->msg, recup->box);
			kill(recup->pid_c, SIGUSR2);
		}
		else
		{
			recup->msg = f_stock_char(recup->msg, recup->box);
			printf("%s\n", recup->msg);
			free(recup->msg);
			recup->msg = NULL;
			kill(recup->pid_c, SIGUSR1);
		}
		recup->box = 0;
		recup->bits = 0;
	}
	else
		kill(recup->pid_c, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_serv;

	(void)argv;
	if (argc > 1)
	{
		printf("🚨"RED" Error : "WHT"No argument needed\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&sa_serv.sa_mask);
	sigaddset(&sa_serv.sa_mask, SIGUSR1);
	sigaddset(&sa_serv.sa_mask, SIGUSR2);
	sa_serv.sa_flags = SA_SIGINFO;
	sa_serv.sa_sigaction = f_handler_serv;
	sigaction(SIGUSR1, &sa_serv, NULL);
	sigaction(SIGUSR2, &sa_serv, NULL);
	printf(CYA"Le pid est :"GRE" %d"WHT"\n", getpid());
	while (1)
		pause();
	return (0);
}
