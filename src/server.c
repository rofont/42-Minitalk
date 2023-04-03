/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/04/03 13:12:57 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	f_handler_recep(int sign)
{
	static unsigned char c = 0;
	static int nb_bit = 0;

	c <<= 1;
	c |= (sign == SIGUSR1);
	nb_bit++;
	if (nb_bit == 8)
	{
		ft_printf("%c\n", c);
		nb_bit = 0;
		c = 0;
	}
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
	ft_printf(G "Le pid est : %d\n"W , getpid());
	while(argc == 1)
	{
		pause();
	}
	return (0);
}