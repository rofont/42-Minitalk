/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:51:58 by rofontai          #+#    #+#             */
/*   Updated: 2023/03/16 15:10:42 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void print_bits(char c)
{
	int i = 128;
	while (i > 0)
	{
		if (i & c)
			ft_printf("1\n");
		else
			ft_printf("0\n");
		i = i >> 1;
	}
}

int main()
{
	print_bits('a');
	return (0);
}