/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/06 12:09:02 by rofontai         ###   ########.fr       */
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
	}
	if (sign == SIGUSR2)
	{
		ft_printf("SIG2 ok \n");
		ft_printf("%d\n", info->si_pid);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	struct sigaction sa_ha;
	sa_ha.sa_sigaction = f_handler;
	if (argc != 3)
	{
		ft_printf( "🚨"R" Error "W": Arguments = EXE, PID_SERVER, MESSAGE \n");
		return (0);
	}
	sigaction(SIGUSR1, &sa_ha, NULL);
	sigaction(SIGUSR2, &sa_ha, NULL);
	ft_printf("%d, %s, ok\n", ft_atoi(argv[1]), argv[2]);
	if (ft_strlen(argv[2]) == 1)
	{
		kill(ft_atoi(argv[1]), SIGUSR1);
		ft_printf("%d\n", getpid());
	}
	else
	{
		kill(ft_atoi(argv[1]), SIGUSR2);
		ft_printf("%d\n", getpid());
	}
	while(1)
	{
		pause();
	}
	return (0);
}