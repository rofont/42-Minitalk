/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:47:38 by romain            #+#    #+#             */
/*   Updated: 2023/04/13 11:00:26 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_serv	*f_init_serv(int pid)
{
	t_serv	*init;

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

t_client	*f_init_client(char *pid, char *str)
{
	static t_client	*init;

	if (!init)
	{
		init = ft_calloc(sizeof(t_client), 1);
		if (!init)
			return (0);
		init->index = 0;
		init->bits = 0;
		init->msg = ft_strdup(str);
		init->len = ft_strlen(str);
		init->pid_c = getpid();
		init->pid_s = ft_atoi(pid);
	}
	return (init);
}

void	f_msg_received(t_client *sent)
{
	ft_printf("👍"MAG" Transmission done !"WHT"\n");
	free(sent->msg);
	free(sent);
	exit(EXIT_SUCCESS);
}

char	*f_re_calloc(char *str, int buf)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), buf);
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

char	*f_stock_char(char *str, char c)
{
	static int	i;
	static int	buff;
	static int	size;

	if (!str)
	{
		i = 0;
		buff = 2;
		size = 0;
		str = ft_calloc(sizeof(char), buff + 1);
	}
	str[i++] = c;
	if (++size == buff)
	{
		buff *= 2;
		str = f_re_calloc(str, buff + 1);
	}
	return (str);
}
