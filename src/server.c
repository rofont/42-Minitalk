/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/13 10:51:01 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	f_re_init_pid(t_serv *serv, siginfo_t *info)
{
	serv->pid_c = info->si_pid;
		serv->bits = 0;
		serv->box = 0;
}

static void	f_print_receive(t_serv *serv)
{
	printf("%s\n", serv->msg);
	free(serv->msg);
	serv->msg = NULL;
	kill(serv->pid_c, SIGUSR1);
}

static void	f_handler_serv(int sign, siginfo_t *info, void *ucontext_t)
{
	static t_serv	*recup;

	(void)ucontext_t;
	if (!recup)
		recup = f_init_serv(info->si_pid);
	if (recup && recup->pid_c != info->si_pid && info->si_pid != 0)
		f_re_init_pid(recup, info);
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
			f_print_receive(recup);
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
