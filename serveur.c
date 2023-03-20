/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:10:10 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/20 15:10:04 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int signal)
{
	static int i;
	static int bit;

	if (signal == SIGUSR1)
		i |= (bit < 1);
	if (signal == SIGUSR2)
		bit++;
}


int main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		// ft_printf(R "Error\n");
		// return (0);
	}
	ft_printf(G "Le pid est : %d\n"W , getpid());
	while(argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}