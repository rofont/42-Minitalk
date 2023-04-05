/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:20:02 by romain            #+#    #+#             */
/*   Updated: 2023/04/05 14:19:03 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_recept *f_init(char *pid, char *str)
{
	static t_recept *new;

	if(!new)
	{
		new = ft_calloc(sizeof(t_recept), 1);
		new->index = 0;
		new->msg = ft_strdup(str);
		new->len = ft_strlen(str);
		new->pid_c = getpid();
		new->pid_s = ft_atoi(pid);
	}
	return (new);
}



int main (int argc, char **argv)
{
	t_recept *enter;

	if (argc != 3)
		ft_printf("🚨 Error arguments\n");
	else
	{
		enter = f_init(argv[1], argv[2]);
		ft_printf("%s\n", enter->msg);
		ft_printf("%d\n", enter->pid_s);
		ft_printf("%d\n", enter->pid_c);

	}
}













// void f_send_bits(int pid, char c)
// {
// 	int i;

// 	i = 128;
// 	while (i > 0)
// 	{
// 		if (i & c)
// 			kill(pid, SIGUSR1);
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(150);
// 		i = i >> 1;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int i;
// 	int pid;

// 	i = 0;
// 	if(argc == 3)
// 	{

// 		pid = ft_atoi(argv[1]);
// 		while (argv[2][i])
// 		{
// 			f_send_bits(pid, argv[2][i++]);
// 		}
// 	}
// 	return (0);
// }