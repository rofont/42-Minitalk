/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:57:00 by rofontai          #+#    #+#             */
/*   Updated: 2022/11/22 10:20:53 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintptr_t	convert(uintptr_t ptr)
{
	int	temp;

	temp = 0;
	if (ptr >= 16)
	{
		temp += convert(ptr / 16);
		temp += convert(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			temp += ft_printchar(ptr + 87);
		else
			temp += ft_printchar(ptr + 48);
	}
	return (temp);
}

int	ft_printptr(void *ptr)
{
	int	temp;

	temp = 0;
	temp += ft_printstr("0x");
	temp += convert((uintptr_t)ptr);
	return (temp);
}
