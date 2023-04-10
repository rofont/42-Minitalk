/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:39:44 by romain            #+#    #+#             */
/*   Updated: 2023/04/09 17:33:18 by romain           ###   ########.fr       */
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

typedef struct	s_recept
{
	char			*msg;
	unsigned char	box;
	size_t			bit;
	pid_t			pid_c;
}			t_recept;

// UTILS-----------------------------------------------------------------------

t_recept *f_init(int pid);

#endif