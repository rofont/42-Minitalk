/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/03/27 16:45:57 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	f_handler_recep(int sign)
{
	static int i;
	static int bit;

	i = 0;
	bit = 0;
	if (sign == SIGUSR1)
		{
			i |= (i << bit);
			bit++;
			ft_printf("j'ai recu 1\n");
		}
	if (bit == 8)
	{
		ft_printf("%c\n", i);
		bit = 0;
		i = 0;
	}
	// if (sign == SIGUSR2)
	// 	ft_printf("J'ai recu 0\n");
	if (sign != SIGUSR1 && sign != SIGUSR2)
		ft_printf("J'ai recu quelque chsoe de bizzare\n");
}



int main(int argc, char **argv)
{
	(void)argv;
	struct sigaction sa_hand;

	sa_hand.sa_flags = SA_SIGINFO;
	sa_hand.sa_handler = f_handler_recep;
	if (argc > 1)
	{
		ft_printf(R "Error : There are too many arguments \n");
		return (0);
	}
	sigaction(SIGUSR1, &sa_hand, NULL);
	sigaction(SIGUSR2, &sa_hand, NULL);
	ft_printf("%d\n", SA_SIGINFO);
	ft_printf(G "Le pid est : %d\n"W , getpid());
	while(argc == 1)
	{
		pause();
	}
	return (0);
}