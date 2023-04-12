/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:44 by romain            #+#    #+#             */
/*   Updated: 2023/04/12 12:59:04 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H


# include "../libft/include/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define R "\x1B[31m"
# define W "\x1B[37m"
# define G "\x1B[32m"
# define C "\x1B[36m"
# define B "\x1B[30m"


// STRUCTURE-------------------------------------------------------------------

typedef struct	s_serv
{
	char			*msg;
	int				index;
	unsigned char	box;
	size_t			bits;
	int				buf;
	pid_t			pid_c;
}					t_serv;

typedef struct s_client
{
	char	*msg;
	int		index;
	int		len;
	size_t	bits;
	pid_t	pid_c;
	pid_t	pid_s;
}			t_client;


// UTILS-----------------------------------------------------------------------

t_serv		*f_init_serv(int pid);
t_client	*f_init_client(char *pid, char *str);
void		f_msg_received(t_client *sent);
char		*f_re_calloc(char *str, int buf);
char 		*f_stock_char(char *str, char c);

#endif