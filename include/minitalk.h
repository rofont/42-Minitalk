/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:44 by romain            #+#    #+#             */
/*   Updated: 2023/04/12 21:17:23 by romain           ###   ########.fr       */
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

// COLOR-----------------------------------------------------------------------

# define BCK "\x1B[30m"
# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLE "\x1B[34m"
# define MAG "\x1B[35m"
# define CYA "\x1B[36m"
# define WHT "\x1B[37m"

// BRIGHT COLOR----------------------------------------------------------------

# define B_BCK "\x1B[90m"
# define B_RED "\x1B[91m"
# define B_GRE "\x1B[92m"
# define B_YEL "\x1B[93m"
# define B_BLE "\x1B[94m"
# define B_MAG "\x1B[95m"
# define B_CYA "\x1B[96m"
# define B_WHT "\x1B[97m"

// STRUCTURE-------------------------------------------------------------------
typedef struct s_serv
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
char		*f_stock_char(char *str, char c);

#endif