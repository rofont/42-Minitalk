/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:08 by romain            #+#    #+#             */
/*   Updated: 2023/03/25 11:15:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		ft_printf(R "Error\n");
		return (0);
	}
	ft_printf(G "Le pid est : %d\n"W , getpid());
	while(argc == 1)
	{
		pause();
	}
	return (0);
}