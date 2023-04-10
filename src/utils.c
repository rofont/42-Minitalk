/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:47:38 by romain            #+#    #+#             */
/*   Updated: 2023/04/09 18:20:26 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_recept *f_init(int pid)
{
	t_recept *init;

	init = ft_calloc(sizeof(t_recept), 1);
	init->box = 0;
	init->bit = 0;
	init->pid_c = pid;
	return (init);
}

