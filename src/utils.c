/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:47:38 by romain            #+#    #+#             */
/*   Updated: 2023/04/11 21:52:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_serv *f_init_serv(int pid)
{
	t_serv *init;

	init = ft_calloc(sizeof(t_serv), 1);
	if (!init)
		return (0);
	init->msg = NULL;
	init->index = 0;
	init->box = 0;
	init->bits = 0;
	init->buf = 2;
	init->pid_c = pid;
	return (init);
}

t_client *f_init_client(char *pid, char *str)
{
	t_client *init;

	init = ft_calloc(sizeof(t_client), 1);
	if (!init)
		return (0);
	init->index = 0;
	init->bits = 0;
	init->msg = ft_strdup(str);
	init->len = ft_strlen(str);
	init->pid_c = getpid();
	init->pid_s = ft_atoi(pid);
	return (init);
}

void f_msg_received(t_client *sent)
{
	printf("Transmission done !\n");
	printf("%d char sended", sent->index);
	free(sent->msg);
	free(sent);
	exit(EXIT_SUCCESS);
}

char *f_re_malloc(char *str, int buf)
{
	char *new;
	int i;

	i = 0;
	new =ft_calloc(sizeof(char), buf);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	return (new);
}

t_serv *f_stock_char(t_serv *recup)
{
	if (!recup->msg)
		recup->msg = ft_calloc(sizeof(char), recup->buf);
			if (!recup->msg)
				return (0);
	if (recup->index == recup->buf)
	{
		recup->buf *= 2;
		recup->msg = f_re_malloc(recup->msg, recup->buf);
	}
	recup->msg[recup->index] = recup->box;
	return (recup);
}