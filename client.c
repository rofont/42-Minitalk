/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:51:58 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/20 15:02:46 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void f_send_bits(int pid, char c)
{
	int i;

	i = 128;
	while (i > 0)
	{
		if (i & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i = i >> 1;
	}
}

int main(int argc, char **argv)
{
	int i;
	int pid;

	i = 0;
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			f_send_bits(pid, argv[2][i++]);
		}
	}
	return (0);
}